#include "Student.hpp"

void Student::input() {
    getline(std::cin, name);
    std::cin >> literature >> math;
    std::cin.ignore();
}

void Student::output() {
    std::cout << name << ' ' << literature << ' ' << math << '\n';
}

std::string Student::getName() {
    return name;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

float Student::getLit() {
    return literature;
}

void Student::setLit(float lit) {
    literature = lit;
}

float Student::getMath() {
    return math;
}

void Student::setMath(float math) {
    this->math = math;
}

float Student::calculateGPA() {
    return (literature + math) / 2;
}

char Student::grade() {
    float gpa = calculateGPA();
    if (gpa >= 9.0) return 'A';
    if (gpa >= 7.0) return 'B';
    if (gpa >= 5.0) return 'C';
    return 'D';
}