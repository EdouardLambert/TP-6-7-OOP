#include "Fraction.hpp"

using namespace std;

Fraction::Fraction()
{
	this->num = 0;
	this->den = 1;
}

Fraction::Fraction(int num, int den)
{
	this->num = num;
	this->den = den;
}

int Fraction::getNum() const
{
	return this->num;
}

int Fraction::getDen() const
{
	return this->den;
}

void Fraction::setNum(int newNum)
{
	this->num = newNum;
}

void Fraction::setDen(int newDen)
{
	if (newDen != 0) {
		this->den = newDen;
	}
}

void Fraction::print()
{
	cout << this->num << " / " << this->den << endl;
}

Fraction Fraction::operator+(const Fraction& other)
{
	return Fraction(this->num * other.den + this->den * other.num, this->den * other.den);
}

Fraction Fraction::operator-(const Fraction& other)
{
	return Fraction(this->num * other.den - other.num * this->den, this->den * other.den);
}

Fraction Fraction::operator*(const Fraction& other)
{
	return Fraction(this->num * other.num, this->den * other.den);
}

Fraction Fraction::operator/(const Fraction& other)
{
	return Fraction(this->num * other.den, this->den * other.num); // divisier par un nombre c'est multiplier par l'inverse
}

int pgcd(int q, int r) // calcul du PGCD
{
	return r == 0 ? q : pgcd(r, q % r); // Algorithme d'Euclide
}

int ppcm(int a, int b) // calcul du PPCM
{
	return (a * b) / pgcd(a, b);
}

void Fraction::reduce()
{
	Fraction f;
	int gcd = pgcd(this->getNum(), this->getDen());
	f.setNum(this->getNum() / gcd);
	f.setDen(this->getDen() / gcd);
}

Fraction Fraction::same_den(int pcm)
{
	Fraction f;
	f.setNum(this->getNum() * (pcm / this->getDen()));;
	f.setDen(pcm);
	return f;
}

bool Fraction::operator==(Fraction other)
{
	Fraction* f1 = this;
	Fraction f2 = other;
	f1->reduce();
	f2.reduce();
	if ((f1->getNum() == f2.getNum()) && (f1->getDen() == f2.getDen()))
	{
		return true;
	}
	return false;
}

bool Fraction::operator!=(Fraction other)
{
	Fraction *f1 = this;
	Fraction f2 = other;
	f1->reduce();
	f2.reduce();
	if ((f1->getNum() != f2.getNum()) || (f1->getDen() != f2.getDen()))
	{
		return true;
	}
	return false;
}

bool Fraction::operator>(Fraction other)
{
	if (this->getDen() != other.getDen())
	{
		int pcm = ppcm(this->getDen(), other.getDen());
		Fraction f1, f2;
		f1.same_den(pcm);
		f2.same_den(pcm);
		if ((f1.getNum() > f2.getNum()))
		{
			return true;
		}
	}
	else if ((this->getNum() > other.getNum()))
	{
		return true;
	}
	return false;
}

bool Fraction::operator<(Fraction other)
{
	if (this->getDen() != other.getDen())
	{
		int pcm = ppcm(this->getDen(), other.getDen());
		Fraction f1, f2;
		f1.same_den(pcm);
		f2.same_den(pcm);
		if ((f1.getNum() < f2.getNum()))
		{
			return true;
		}
	}
	else if ((this->getNum() < other.getNum()))
	{
		return true;
	}
	return false;
}

bool Fraction::operator>=(Fraction other)
{
	if (this->getDen() != other.getDen())
	{
		int pcm = ppcm(this->getDen(), other.getDen());
		Fraction f1, f2;
		f1.same_den(pcm);
		f2.same_den(pcm);
		if ((f1.getNum() >= f2.getNum()))
		{
			return true;
		}
	}
	else if ((this->getNum() >= other.getNum()))
	{
		return true;
	}
	return false;
}

bool Fraction::operator<=(Fraction other)
{
	if (this->getDen() != other.getDen())
	{
		int pcm = ppcm(this->getDen(), other.getDen());
		Fraction f1, f2;
		f1.same_den(pcm);
		f2.same_den(pcm);
		if ((f1.getNum() <= f2.getNum()))
		{
			return true;
		}
	}
	else if ((this->getNum() <= other.getNum()))
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f.getNum() << "/" << f.getDen();
	return os;
}

istream& operator>>(istream& is, Fraction& f)
{
	is >> f.num >> f.den;
	f.reduce();
	return is;
}