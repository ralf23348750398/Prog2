#pragma once

#include <stdexcept>

using namespace std;


template <class T>
T id(T x) { return x; }


template <class S, class T>
T aggregate(S* a, int size,
    T(*g)(T, T) = [](T x, T y) -> T { return x + y; },
    T(*f)(S) = id) {
    if (size > 0) {
        T v = f(a[0]);
        for (int i = 1; i < size; i++) {
            v = g(v, f(a[i]));
        }
        return v;
    } else throw logic_error("Received array of size " + size);
}
