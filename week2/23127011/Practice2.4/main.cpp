#include "Array.hpp"

bool compare(int a, int b) {
    return a > b;
}

int main() {
    try {
        Array arr;
        arr.input();
        arr.output();

        std::cout << "Size of the array: " << arr.getElements(10) << '\n';

        arr.setSize(10);

        arr.output();

        std::cout << "Element at index 3: " << arr.getElements(3) << '\n';

        arr.setElements(3, 100);

        arr.output();

        std::cout << "Index of 100: " << arr.find(100) << '\n';

        arr.sort();
        arr.output();

        arr.sort(compare);

        arr.output();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}