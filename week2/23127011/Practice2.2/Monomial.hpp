#pragma once
#include <iostream>
#include <cmath>
#include <numeric>
class Monomial {

    // ax^b
    // a is the coefficient
    // b is the exponent

    int coefficient;
    int exponent;

public:
    void input();
    void output();

    int getCoef();
    void setCoef(int coef);

    int getExpo();
    void setExpo(int exp);

    float evaluate(float x);
    Monomial derive();
    Monomial mul(const Monomial& other);
};