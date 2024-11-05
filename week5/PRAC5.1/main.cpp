#include "Polynomial.h"

int main() {

    Polynomial p1;

    int deg = 2;
    float coefs[] = { 1, 2, 3 };

    Polynomial p2(deg, coefs);

    std::cout << p1 + p2 << '\n';
    std::cout << p2 + p1 << '\n';
    std::cout << p2 << '\n';
    std::cout << !p2 << '\n';
    std::cout << !p2 << '\n';
    std::cout << p2 << '\n';

    std::cout << (p2 + ~p2) << '\n';
    std::cout << (p2 * ~p2) << '\n';
    std::cout << (p2 + (!p2)) << '\n';

    std::cout << p2 << ' ' << !p2 << '\n';
    p2 += !p2;
    std::cout << p2 << '\n';

    std::cout << p2 << ' ' << ~p2 << '\n';
    p2 *= ~p2;

    std::cout << p2 << '\n';

    // std::cout << p2.getDegree() << '\n';
    // std::cout << p2.getCoefOfDeg(0) << '\n';
    // p2.setCoefOfDeg(3, 6);
    // std::cout << p2 << '\n';
    // std::cout << p2.getCoefOfDeg(0) << '\n';
    std::cout << "-------------------\n";

    Polynomial p3(p2);
    std::cout << "p3 created\n";
    Polynomial p4(p2 + p1);
    std::cout << p3 << '\n';

    // std::cout << p4 * 3 << '\n';
    // std::cout << p4 + 3 << '\n';
    // std::cout << p4 / 3 << '\n';
    // std::cout << p4 - 3 << '\n';

    // std::cout << (p4 == p2) << '\n';
    // std::cout << (p4 != p2) << '\n';
    // std::cout << (p4 < p2) << '\n';
    // std::cout << (p4 <= p2) << '\n';
    // std::cout << (p4 > p2) << '\n';
    // std::cout << (p4 >= p2) << '\n';


    return 0;

}