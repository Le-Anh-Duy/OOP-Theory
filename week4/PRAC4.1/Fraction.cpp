#include "Fraction.h"


Fraction::Fraction() : m_num(0), m_den(1) {};
Fraction::Fraction(int num, int den) : m_num(num), m_den(den) {};
Fraction::Fraction(const Fraction& f) : m_num(f.m_num), m_den(f.m_den) {};
Fraction::~Fraction() {};

Fraction Fraction::simplyfy() const {
    int gcd = std::__gcd(m_num, m_den);
    int sign = (m_num < 0) ^ (m_den < 0) ? -1 : 1;

    return Fraction(sign * m_num / gcd, sign * m_den / gcd);
}

Fraction::operator float() const {
    return (float)m_num / m_den;
}

Fraction::operator int() const {
    return m_num / m_den;
}

Fraction& Fraction::operator=(const Fraction& f) {
    m_num = f.m_num;
    m_den = f.m_den;
    return *this;
}

Fraction Fraction::operator+(const Fraction& f) const {
    return Fraction(m_num * f.m_den + f.m_num * m_den, m_den * f.m_den);
}

Fraction Fraction::operator-(const Fraction& f) const {
    return Fraction(m_num * f.m_den - f.m_num * m_den, m_den * f.m_den);
}

Fraction Fraction::operator*(const Fraction& f) const {
    return Fraction(m_num * f.m_num, m_den * f.m_den);
}

Fraction Fraction::operator/(const Fraction& f) const {
    return Fraction(m_num * f.m_den, m_den * f.m_num);
}

bool Fraction::operator==(const Fraction& f) const {
    Fraction A = simplyfy();
    Fraction B = f.simplyfy();

    return A.m_num == B.m_num && A.m_den == B.m_den;
}

bool Fraction::operator!=(const Fraction& f) const {
    return !(*this == f);
}

bool Fraction::operator<(const Fraction& f) const {
    if (*this == f) return false;
    return float(*this) < float(f);
}

bool Fraction::operator<=(const Fraction& f) const {
    return *this < f || *this == f;
}

bool Fraction::operator>(const Fraction& f) const {
    return !(*this <= f);
}

bool Fraction::operator>=(const Fraction& f) const {
    return !(*this < f);
}

Fraction& Fraction::operator+=(const Fraction& f) {
    *this = *this + f;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& f) {
    *this = *this - f;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& f) {
    *this = *this * f;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& f) {
    *this = *this / f;
    return *this;
}

Fraction& Fraction::operator++() {
    m_num += m_den;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    m_num += m_den;
    return temp;
}

Fraction& Fraction::operator--() {
    m_num -= m_den;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    m_num -= m_den;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.m_num << "/" << f.m_den;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    is >> f.m_num;
    is.ignore(1);
    is >> f.m_den;
    return is;
}