#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>

class Fraction
{
private:
    int m_num;
    int m_den;

public:

    Fraction simplyfy() const;

    Fraction();
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction& f);
    ~Fraction();

    Fraction& operator=(const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;

    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // float casting
    operator float() const;
    operator int() const;

    // assignment operators
    Fraction& operator+=(const Fraction& f);
    Fraction& operator-=(const Fraction& f);
    Fraction& operator*=(const Fraction& f);
    Fraction& operator/=(const Fraction& f);

    // increment and decrement operators

    Fraction& operator++(); // pre-increment
    Fraction operator++(int); // post-increment
    Fraction& operator--(); // pre-decrement
    Fraction operator--(int); // post-decrement

};
