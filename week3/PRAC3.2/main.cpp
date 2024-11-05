#include "Student.h"

using namespace std;

int main() {

    Student a("Alice\0kjasd", 100, 90);
    Student b("John");
    Student c(a);

    return 0;
}