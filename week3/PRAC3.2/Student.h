#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Student
{
private:
    char* m_name = nullptr;
    float m_math;
    float m_lit;

public:
    Student(const Student& student);
    Student(const char* name, float math, float lit);
    Student(const char* name);
    ~Student();
};