// test monomial

#include "Monomial.h"

int main() {

    // test monomial
    Monomial m1(2, 3);
    Monomial m2(3, 3);

    std::cout << "m1 = " << m1 << std::endl;
    std::cout << "m2 = " << m2 << std::endl;
    std::cout << "m1 + m2 = " << m1 + m2 << std::endl;
    std::cout << "m1 * m2 = " << m1 * m2 << std::endl;
    std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
    std::cout << "m1 != m2: " << (m1 != m2) << std::endl;
    std::cout << "m1 < m2: " << (m1 < m2) << std::endl;
    std::cout << "m1 <= m2: " << (m1 <= m2) << std::endl;
    std::cout << "m1 > m2: " << (m1 > m2) << std::endl;
    std::cout << "m1 >= m2: " << (m1 >= m2) << std::endl;

    // test assignment operators

    m1 += m2;
    std::cout << "m1 += m2: " << m1 << std::endl;
    m1 *= m2;
    std::cout << "m1 *= m2: " << m1 << std::endl;

    // test increment and decrement operators

    std::cout << "m1++: " << m1++ << std::endl;
    std::cout << "m1: " << m1 << std::endl;
    std::cout << "m1--: " << m1-- << std::endl;
    std::cout << "m1: " << m1 << std::endl;

    // post increment and decrement
    std::cout << "++m1: " << ++m1 << std::endl;
    std::cout << "m1: " << m1 << std::endl;
    std::cout << "--m1: " << --m1 << std::endl;
    std::cout << "m1: " << m1 << std::endl;

    return 0;



}