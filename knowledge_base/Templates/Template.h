#pragma once

template <class T, int size>
class myFancyArray {
public:
    myFancyArray(T default_val);
    ~myFancyArray();

    void set(T val, int index);
    T get(int index);
private:
    T* arr;
};
