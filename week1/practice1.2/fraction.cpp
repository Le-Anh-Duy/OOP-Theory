#include "fraction.hpp"

int __gcd(int a, int b) {
    if (a == 0) return b;
    return __gcd(b % a, a);
}

Fraction::Fraction(int x, int y) {

    if (y == 0) {
        throw runtime_error("Division by zero not allowed!");;
    }

    if (y < 0) x *= -1, y *= -1;
    if (x == 0) y = 1;

    numerator = x;
    denominator = y;
}

void Fraction::input() {
    int x, y;
    cout << "Input numerator:    ";
    cin >> x;
    cout << "Output denominator: ";
    cin >> y;
    *this = Fraction(x, y);
}

void Fraction::output() {
    cout << "Fraction: " << numerator << "/" << denominator << '\n';
}

Fraction reduce(Fraction a) {
    int gcd = __gcd(a.denominator, a.numerator);
    a.denominator /= gcd;
    a.numerator /= gcd;
    return a;
}

Fraction add(Fraction a, Fraction b) {
    a = reduce(a);
    b = reduce(b);
    Fraction result(a.numerator * b.denominator + b.numerator * a.denominator, b.denominator * a.denominator);
    return result;
}

Fraction inverse(Fraction a) {
    return Fraction(a.denominator, a.numerator);
}

int compare(Fraction a, Fraction b) {
    long long A = a.numerator * b.denominator;
    long long B = a.denominator * b.numerator;

    if (A == B) return 0;
    if (A > B) return 1;
    return -1;
}

bool operator< (const Fraction a, const Fraction b)
{
    return compare(a, b) == -1;
}
