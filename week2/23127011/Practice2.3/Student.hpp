#pragma once
#include <iostream>
#include <string>

class Student {
    std::string name;
    float literature;
    float math;

public:
    void input();
    void output();

    std::string getName();
    void setName(const std::string& name);

    float getLit();
    void setLit(float lit);

    float getMath();
    void setMath(float math);

    float calculateGPA();
    char grade();
};