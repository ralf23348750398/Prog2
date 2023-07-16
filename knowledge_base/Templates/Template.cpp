#pragma once

#include "Template.h"

template <class T, int size>
myFancyArray<T, size>::myFancyArray(T default_val) {
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = default_val;
    }
}

template <class T, int size>
myFancyArray<T, size>::~myFancyArray() {
    delete[] arr;
}

template <class T, int size>
void myFancyArray<T, size>::set(T val, int index) {
    arr[index] = val;
}

template <class T, int size>
T myFancyArray<T, size>::get(int index) {
    return arr[index];
}


