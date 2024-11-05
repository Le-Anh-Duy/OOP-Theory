#include "Fraction.hpp"

int main() {

    try
    {
        Fraction a, b;
        a.input();
        b.input();

        Fraction sum = a.add(b);
        sum.output();

        std::cout << a.compare(b) << std::endl;
        std::cout << a.reduce().getNum() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}