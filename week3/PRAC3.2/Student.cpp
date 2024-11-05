#include "Student.h"

Student::Student(const Student& student)
{

    int nameSize = strlen(student.m_name);

    std::cout << student.m_name << " has size :" << nameSize << '\n';

    m_name = new char[nameSize + 1];
    m_name[nameSize] = '\0';

    strcpy(m_name, student.m_name);
    m_math = student.m_math;
    m_lit = student.m_lit;

    std::cout << "Copy constructor called for " << m_name << std::endl;

}

Student::Student(const char* name, float math, float lit)
{
    int nameSize = strlen(name);

    m_name = new char[nameSize + 1];
    m_name[nameSize] = '\0';

    strcpy(m_name, name);
    m_math = math;
    m_lit = lit;

    std::cout << "Full member constructor called for " << m_name << std::endl;
}

Student::Student(const char* name)
{
    int nameSize = strlen(name);

    m_name = new char[nameSize + 1];
    m_name[nameSize] = '\0';

    strcpy(m_name, name);
    m_math = 0;
    m_lit = 0;

    std::cout << "Only name constructor called for " << m_name << std::endl;
}

Student::~Student()
{
    std::cout << "Destructor called for " << m_name << std::endl;
    if (!m_name) return;
    delete[] m_name;

}