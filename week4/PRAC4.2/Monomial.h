#pragma once
#include <iostream>
#include <exception>

class Monomial
{
private:
    int m_coef;
    int m_expo;

public:

    Monomial();
    Monomial(int coef, int expo);
    Monomial(const Monomial& m);
    ~Monomial();


    Monomial operator+(const Monomial& m) const;
    Monomial operator*(const Monomial& m) const;

    bool operator==(const Monomial& m) const;
    bool operator!=(const Monomial& m) const;
    bool operator<(const Monomial& m) const;
    bool operator<=(const Monomial& m) const;
    bool operator>(const Monomial& m) const;
    bool operator>=(const Monomial& m) const;

    Monomial& operator+=(const Monomial& m);
    Monomial& operator*=(const Monomial& m);
    Monomial& operator=(const Monomial& m);

    Monomial& operator++();
    Monomial operator++(int);
    Monomial& operator--();
    Monomial operator--(int);

    Monomial operator!();

    friend std::ostream& operator<<(std::ostream& os, const Monomial& m);
    friend std::istream& operator>>(std::istream& is, Monomial& m);

};