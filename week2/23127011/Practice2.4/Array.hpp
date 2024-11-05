#pragma once
#include <iostream>
#include <exception>

class Array {
    int* data;
    int size;

public:
    void input();
    void output();

    int getSize();

    /*
        if the size is smaller than the current size, the array will be truncated
        if the size is larger than the current size, the new elements will be initialized to 0 at the end of the array
    */
    void setSize(int newSize);

    int getElements(int idx);
    void setElements(int idx, int value);

    /*
        look for an element and return found index (-1 if not found).
    */
    int find(int value);


    /*
        sort with costum compare function
        if compare(a, b) return true, a will be placed before b
        if no compare function is provided, sort in ascending order
    */
    void sort(bool (*compare)(int, int) = NULL);

};