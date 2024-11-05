#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;


struct Fraction {
    int numerator;
    int denominator;

    Fraction(int x, int y); //: numerator(x), denominator(y) {};
    Fraction() {};

    //    input 2 integers on 2 lines
    void input();
    //    output the fraction in term of x/y
    void output();

    friend bool operator< (const Fraction a, const Fraction b);
};

 // add(a, b) -> return a + b

Fraction add(Fraction a, Fraction b);
Fraction reduce(Fraction a);
Fraction inverse(Fraction a);

/*
     1 if a > b
    -1 if a < b
     0 if a = b
*/
int compare(Fraction a, Fraction b);
