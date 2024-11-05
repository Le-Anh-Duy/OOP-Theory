#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>
using namespace std;


class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int x, int y); //: numerator(x), denominator(y) {};
    Fraction() {Fraction(0, 1);};
    /*
        input 2 integers on 2 lines
    */
    void input();

    /*
        output the fraction in term of x/y
    */
    void output();


    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);
    void reduce();
    int compare(Fraction other);
    bool isPositive();
    bool isNegative();
    bool isZero();

};

 // add(a, b) -> return a + b

Fraction add(Fraction a, Fraction b);
Fraction subtract(Fraction a, Fraction b);
Fraction multiply(Fraction a, Fraction b);

/*
    devide 2 fraction, throw if zero
*/
Fraction divide(Fraction a, Fraction b);

Fraction Reduce(Fraction a);

/*
        1 if a > b
    -1 if a < b
        0 if a = b
*/
int Compare(Fraction a, Fraction b);

Fraction inverse(Fraction a);


int __gcd(int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0) return b;
    return __gcd(b % a, a);
}

Fraction::Fraction(int x, int y) {

    if (y == 0) {
        throw std::runtime_error("Division by zero not allowed!");
    }

    numerator = x;
    denominator = y;
}

void Fraction::input() {
    int x, y;
    cin >> x >> y;
    *this = Fraction(x, y);
}

void Fraction::output() {
    cout << numerator << "/" << denominator << '\n';
}

Fraction Reduce(Fraction a) {
    int gcd = __gcd(a.denominator, a.numerator);
    a.denominator /= gcd;
    a.numerator /= gcd;
    return a;
}

Fraction add(Fraction a, Fraction b) {
    Fraction result(a.numerator * b.denominator + b.numerator * a.denominator, b.denominator * a.denominator);
    return result;
}

Fraction subtract(Fraction a, Fraction b) {
    b.numerator *= -1;
    return add(a, b);
}

Fraction multiply(Fraction a, Fraction b) {
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction inverse(Fraction a) {
    return Fraction(a.denominator, a.numerator);
}


Fraction divide(Fraction a, Fraction b) {
    return multiply(a, inverse(b));
}

int Compare(Fraction a, Fraction b) {
    double A = a.numerator / a.denominator;
	double B = b.numerator / b.denominator;

    if (A == B) return 0;
    if (A > B) return 1;
    return -1;
}

bool Fraction::isPositive() {
    return 1.0 * numerator / denominator > 0;
}

bool Fraction::isZero() {
    return numerator == 0;
}

bool Fraction::isNegative() {
    return !this->isPositive() && !this->isZero();
}

Fraction Fraction::operator+(const Fraction& other) {
    return add(*this, other);
}

Fraction Fraction::operator-(const Fraction& other) {
    return subtract(*this, other);
}

Fraction Fraction::operator*(const Fraction& other) {
    return multiply(*this, other);
}

Fraction Fraction::operator/(const Fraction& other) {
    return divide(*this, other);
}

void Fraction::reduce() {
    *this = Reduce(*this);
}

int Fraction::compare(Fraction other) {
    return Compare(other, *this);
}

#include "main.h"