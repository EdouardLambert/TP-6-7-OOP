#include <iostream>

using namespace std;

class Fraction {
private:
    int num;
    int den;
public:
    Fraction(int num, int den);
    explicit Fraction(int num);
    Fraction();
    Fraction(const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    Fraction operator-() const;
    Fraction operator+() const;
    Fraction operator+=(const Fraction& f);
    Fraction operator-=(const Fraction& f);
    Fraction operator*=(const Fraction& f);
    Fraction operator/=(const Fraction& f);
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
    [[nodiscard]] int getNum() const;
    [[nodiscard]] int getDen() const;
    void setNum(int num_);
    void setDen(int den_);
    void simplifier();
    ~Fraction();
};