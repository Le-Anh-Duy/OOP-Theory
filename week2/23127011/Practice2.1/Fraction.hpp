#pragma once
#include <iostream>
#include <string>
#include <exception>

class Fraction {
    int denominator;
    int numerator;

public:
    void input();
    void output();

    int getNum();
    void setNum(int num);

    int getDenom();
    void setDenom(int denom);

    Fraction reduce();
    Fraction inverse();

    Fraction add(const Fraction& other);

    int compare(const Fraction& other);
};