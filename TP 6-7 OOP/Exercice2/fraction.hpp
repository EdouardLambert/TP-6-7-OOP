#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

class Fraction
{
private:
	int num = 0;
	int den = 1;
public:
	Fraction();
	Fraction(int num, int den);
	int getNum() const;
	int getDen() const;
	void setNum(int newNum);
	void setDen(int newDen);
	void print();
	void reduce();
	Fraction same_den(int pcm); // met la fraction sur un denominateur commun avec une autre fraction
	Fraction operator+(const Fraction& other); // +
	Fraction operator-(const Fraction& other); // -
	Fraction operator*(const Fraction& other); // *
	Fraction operator/(const Fraction& other); // /
	bool operator==(Fraction other); // ==
	bool operator!=(Fraction other); // !=
	bool operator>(Fraction other); // >
	bool operator<(Fraction other); // <
	bool operator>=(Fraction other); // >=
	bool operator<=(Fraction other); // <=
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	friend std::istream& operator>>(std::istream& is, Fraction& f);
};

int pgcd(int q, int r);

int ppcm(int a, int b);