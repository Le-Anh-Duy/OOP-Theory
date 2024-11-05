// test Array
#include "Array.h"

int main() {

    Array <int> arr(5);

    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    Array <int> arr2 = arr;

    std::cout << arr2 << '\n';

    std::cout << (int *)arr2 << '\n';
    std::cout << &arr2[0] << '\n';

    return 0;

}