#include "Fraction.h"

int main() {

    // test fraction
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;
    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2: " << (f1 != f2) << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2: " << (f1 <= f2) << std::endl;
    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2: " << (f1 >= f2) << std::endl;

    // test float casting

    std::cout << "float(f1) = " << float(f1) << std::endl;
    std::cout << "int(f1) = " << int(f1) << std::endl;

    // test assignment operators

    f1 += f2;
    std::cout << "f1 += f2: " << f1 << std::endl;
    f1 -= f2;
    std::cout << "f1 -= f2: " << f1 << std::endl;
    f1 *= f2;
    std::cout << "f1 *= f2: " << f1 << std::endl;
    f1 /= f2;
    std::cout << "f1 /= f2: " << f1 << std::endl;
    // test increment and decrement operators

    std::cout << "f1++: " << f1++ << std::endl;
    std::cout << "f1: " << f1 << std::endl;
    std::cout << "++f1: " << ++f1 << std::endl;
    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f1--: " << f1-- << std::endl;
    std::cout << "f1: " << f1 << std::endl;
    std::cout << "--f1: " << --f1 << std::endl;
    std::cout << "f1: " << f1 << std::endl;

    return 0;
}