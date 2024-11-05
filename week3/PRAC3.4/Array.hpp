#pragma once

#include <iostream>
#include <exception>

template <class T>
class Array {
private:
    int m_size;
    T* m_arr;

public:


    Array(){
        m_size = 0;
        m_arr = nullptr;
    };

    Array(int size): m_size(size) {

        if (m_size == 0) return;

        if (m_size < 0) {
            m_size = 0;
            throw std::runtime_error("Array size need to be non-negative!!");
        }

        m_arr = new T[size];
        for (int i = 0; i < size; i++)
            m_arr[i] = T();
    }

    Array(int size, T arr[]): m_size(size) {

        if (m_size < 0) {
            m_size = 0;
            throw std::runtime_error("Array size need to be non-negative!!");
        }

        m_arr = new T[size];
        for (int i = 0; i < size; i++)
            m_arr[i] = arr[i];
    }

    Array(const Array<T>& arr): m_size(arr.m_size) {

        m_arr = new T[m_size];
        for (int i = 0; i < m_size; i++)
            m_arr[i] = T(arr.m_arr[i]);
    }

    Array(int size, const T& value): m_size(size) {
        if (m_size < 0) {
            m_size = 0;
            throw std::runtime_error("Array size need to be non-negative!!");
        }

        m_arr = new T[size];
        for (int i = 0; i < size; i++)
            m_arr[i] = value;
    }

    ~Array() {
        if (m_size == 0) {
            m_arr = NULL;
            return;
        }

        delete[] m_arr;
        m_size = 0;
    }

    void operator= (const Array<T>& other) {
        m_size = other.m_size;
        m_arr = new T[m_size];

        for (int i = 0; i < m_size; i ++)
            m_arr[i] = other.m_arr[i];
    }

    T& getElement(int index) {
        return m_arr[index];
    }

    int getSize() {
        return m_size;
    }

};