#pragma once

#include <iostream>

using namespace std;

template <class T, unsigned int sizeFakt, unsigned int initialSize>
class FlexArray {

public:
	FlexArray(T defaultValue){
		this->defaultValue = defaultValue;
		data = new T[initialSize];
		for (int i = 0; i < initialSize; i++) {
			data[i] = defaultValue;
		}
		currentSize = initialSize;
	}

	~FlexArray() {
		delete[] data;
	}

	T get(unsigned int index) {
		while (index >= currentSize) {
			enlargeArray();
		}
		return data[index];
	}

	void set(unsigned int index, T value) {
		while (index >= currentSize) {
			enlargeArray();
		}
		data[index] = value;
	}

	void print() {
		cout << "The values of the current array:" << endl;
		for (int i = 0; i < currentSize; i++) {
			cout << "index " << i << ": " << data[i] << endl;
		}
		cout << endl;
	}

	void exchange(unsigned int index1, unsigned int index2) {
		while (index1 >= currentSize || index2 >= currentSize) {
			enlargeArray();
		}
		T cache = data[index1];
		data[index1] = data[index2];
		data[index2] = cache;
	}

private:
	T* data;
	unsigned int currentSize;
	T defaultValue;

	void enlargeArray() {
		//save data of original array in cache and delete original array
		T* cacheArray = new T[currentSize];
		for (int i = 0; i < currentSize; i++) {
			cacheArray[i] = data[i];
		}
		delete[] data;

		//create bigger array data and initialize data
		unsigned int oldSize = currentSize;
		currentSize *= sizeFakt;
		data = new T[currentSize];
		for (int i = 0; i < currentSize; i++) {
			data[i] = defaultValue;
		}

		for (int i = 0; i < oldSize; i++) {
			data[i] = cacheArray[i];
		}
		delete[] cacheArray;
	}
};