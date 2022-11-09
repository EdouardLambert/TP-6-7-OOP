#include "fraction.hpp"

Fraction::Fraction(int num, int den) {
    this->num = num;
    this->den = den;
    simplifier();
}

Fraction::Fraction(int num) {
    this->num = num;
    this->den = 1;
}

Fraction::Fraction() {
    this->num = 0;
    this->den = 1;
}

Fraction::Fraction(const Fraction& f) {
    this->num = f.num;
    this->den = f.den;
}

Fraction Fraction::operator+(const Fraction& f) const {
    Fraction res;
    res.num = this->num * f.den + this->den * f.num;
    res.den = this->den * f.den;
    res.simplifier();
    return res;
}

Fraction Fraction::operator-(const Fraction& f) const {
    Fraction res;
    res.num = this->num * f.den - this->den * f.num;
    res.den = this->den * f.den;
    res.simplifier();
    return res;
}

Fraction Fraction::operator*(const Fraction& f) const {
    Fraction res;
    res.num = this->num * f.num;
    res.den = this->den * f.den;
    res.simplifier();
    return res;
}

Fraction Fraction::operator/(const Fraction& f) const {
    Fraction res;
    res.num = this->num * f.den;
    res.den = this->den * f.num;
    res.simplifier();
    return res;
}

Fraction Fraction::operator-() const {
    Fraction res;
    res.num = -this->num;
    res.den = this->den;
    return res;
}

Fraction Fraction::operator+() const {
    Fraction res;
    res.num = this->num;
    res.den = this->den;
    return res;
}

Fraction Fraction::operator+=(const Fraction& f) {
    this->num = this->num * f.den + this->den * f.num;
    this->den = this->den * f.den;
    simplifier();
    return *this;
}

Fraction Fraction::operator-=(const Fraction& f) {
    this->num = this->num * f.den - this->den * f.num;
    this->den = this->den * f.den;
    simplifier();
    return *this;
}

Fraction Fraction::operator*=(const Fraction& f) {
    this->num = this->num * f.num;
    this->den = this->den * f.den;
    simplifier();
    return *this;
}

Fraction Fraction::operator/=(const Fraction& f) {
    this->num = this->num * f.den;
    this->den = this->den * f.num;
    simplifier();
    return *this;
}

bool Fraction::operator==(const Fraction& f) const {
    return this->num == f.num && this->den == f.den;
}

bool Fraction::operator!=(const Fraction& f) const {
    return this->num != f.num || this->den != f.den;
}

bool Fraction::operator<(const Fraction& f) const {
    return this->num * f.den < this->den* f.num;
}

bool Fraction::operator>(const Fraction& f) const {
    return this->num * f.den > this->den * f.num;
}

bool Fraction::operator<=(const Fraction& f) const {
    return this->num * f.den <= this->den * f.num;
}

bool Fraction::operator>=(const Fraction& f) const {
    return this->num * f.den >= this->den * f.num;
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.getNum() << "/" << f.getDen();
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    is >> f.num >> f.den;
    return is;
}

void Fraction::simplifier() {
    int a = this->num;
    int b = this->den;
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    this->num /= b;
    this->den /= b;
}

int Fraction::getNum() const {
    return num;
}

void Fraction::setNum(int num_) {
    Fraction::num = num_;
}

int Fraction::getDen() const {
    return den;
}

void Fraction::setDen(int den_) {
    Fraction::den = den_;
}

Fraction::~Fraction() = default;