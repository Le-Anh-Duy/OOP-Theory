#include "Array.hpp"

void Array::input() {
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    data = new int[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> data[i];
    }
}

void Array::output() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << '\n';
}

int Array::getSize() {
    return size;
}

void Array::setSize(int newSize) {
    int* newData = new int[newSize];

    for (int i = 0; i < newSize; i ++)
        newData[i] = 0;

    for (int i = 0; i < newSize && i < this->size; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    this->size = newSize;
}

int Array::getElements(int idx) {
    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");

    return data[idx];
}

void Array::setElements(int idx, int value) {
    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");

    data[idx] = value;
}

int Array::find(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value)
            return i;
    }

    return -1;
}

void Array::sort(bool (*compare)(int, int)) {
    if (compare == NULL) {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (data[i] > data[j])
                    std::swap(data[i], data[j]);
    } else {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (compare(data[j], data[i]))
                    std::swap(data[i], data[j]);
    }
}