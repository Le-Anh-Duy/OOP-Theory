#include "Fraction.hpp"

void Fraction::input() {
    std::cin >> numerator >> denominator;
    if (denominator == 0) throw std::runtime_error("Denominator cannot be 0");
}

void Fraction::output() {
    std::cout << numerator << "/" << denominator << '\n';
}

int Fraction::getNum() {
    return numerator;
}

void Fraction::setNum(int num) {
    numerator = num;
}

int Fraction::getDenom() {
    return denominator;
}

void Fraction::setDenom(int denom) {
    denominator = denom;
}

int findGCD(int a, int b) {
    if (b == 0) return a;
    return findGCD(b, a % b);
}

Fraction Fraction::reduce() {
    int gcd = findGCD(numerator, denominator);

    Fraction ans;

    ans.setNum(numerator / gcd);
    ans.setDenom(denominator / gcd);
    return ans;
}

Fraction Fraction::inverse() {
    if (numerator == 0) throw std::runtime_error("Cannot inverse 0");
    Fraction ans;
    ans.setDenom(numerator);
    ans.setNum(denominator);

    return ans;
}

Fraction Fraction::add(const Fraction& other) {

    Fraction ans;
    ans.setNum(numerator * other.denominator + other.numerator * denominator);
    ans.setDenom(denominator * other.denominator);

    return ans;
}

int Fraction::compare(const Fraction& other) {

    double a = (double)numerator / denominator;
    double b = (double)other.numerator / other.denominator;

    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}