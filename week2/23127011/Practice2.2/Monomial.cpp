#include "Monomial.hpp"

void Monomial::input() {
    std::cin >> coefficient >> exponent;
}

void Monomial::output() {
    std::cout << coefficient << "x^" << exponent << '\n';
}

int Monomial::getCoef() {
    return coefficient;
}

void Monomial::setCoef(int coef) {
    coefficient = coef;
}

int Monomial::getExpo() {
    return exponent;
}

void Monomial::setExpo(int exp) {
    exponent = exp;
}

float Monomial::evaluate(float x) {
    return coefficient * pow(x, exponent);
}

Monomial Monomial::derive() {
    Monomial ans;
    ans.setCoef(coefficient * exponent);
    ans.setExpo(exponent - 1);
    return ans;
}

Monomial Monomial::mul(const Monomial& other) {
    Monomial ans;
    ans.setCoef(coefficient * other.coefficient);
    ans.setExpo(exponent + other.exponent);
    return ans;
}
