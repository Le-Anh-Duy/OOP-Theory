#include "Student.hpp"


int main() {
    Student A, B;
    A.input();
    B.input();



    A.output();
    B.output();

    std::cout << A.calculateGPA() << '\n';
    std::cout << A.grade() << '\n';



    return 0;
}