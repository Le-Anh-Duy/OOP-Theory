#pragma once
/*
Provide class Array (elements of any type) the following operators:
Assignment: =.
 Array indexer: [ ].
Type-cast: (T *) (to T pointer). cast: (T *) (to T pointer).
Input/Output: >>, <<.
*/

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <exception>

template <typename T>
class Array
{
private:
    T *m_arr;
    size_t m_size;

public:

    Array(size_t size = 0) : m_size(size) {
        if (size == 0) {
            m_arr = nullptr;
            return;
        }

        if (size < 0) {
            throw std::invalid_argument("Size must be greater than 0.");
        }

        m_arr = new T[size];
    }

    Array(const Array& arr) : m_size(arr.m_size) {
        m_arr = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = arr.m_arr[i];
        }
    }

    ~Array() {
        if (m_arr != nullptr)
            delete[] m_arr;
    }

    Array& operator=(const Array& arr) {
        if (this == &arr) return *this;

        delete[] m_arr;

        m_size = arr.m_size;
        m_arr = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = arr.m_arr[i];
        }

        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range.");
        }

        return m_arr[index];
    }

    operator T*() {
        return m_arr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (int i = 0; i < arr.m_size; i++) {
            os << arr.m_arr[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
        for (int i = 0; i < arr.m_size; i++) {
            is >> arr.m_arr[i];
        }
        return is;
    }


};