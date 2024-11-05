#include "Monomial.hpp"

int main() {
    Monomial m1, m2;
    m1.input();
    m2.input();

    Monomial m3 = m1.mul(m2);
    m3.output();

    m3.derive().output();

    std::cout << m3.evaluate(23.351) << '\n';;

    return 0;
}