#pragma once
#include <iostream>
#include <stdexcept>

/*
    - Sort with custom compare function
    - If compare(A, B) == true then A should comes before B in the array
    - EX:
    ```
        bool cmp(int a, int b) {
            return a > b;
        }

        ...

        sort(arr, n, cmp); should sort the array decending
    ```
*/
template <class T>
void sort(T *arr, int size, bool (* compare)(T, T)) {
    for (int i = 0; i < size - 1; i ++) {
        for (int j = i + 1; j < size; j ++)
            if (!compare(arr[i], arr[j]))
                swap(arr[i], arr[j]);
    }
}