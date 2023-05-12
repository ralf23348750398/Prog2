
#include <iostream>
#include <algorithm>
#include <string>
#include "BinaryRelation.h"
#include "Color.h"

using namespace std;


string to_string(Color& c) {
	return "(" + std::to_string(c.getRed()) + ", " + to_string(c.getGreen()) + ", " + to_string(c.getBlue()) + ")";
}

template <class T>
void printArray(T* a, int size) {
	cout << "------------------------------------------------------" << endl;
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << to_string(a[i]);
		if (i < size - 1) cout << ", ";
	}
	cout << "]" << endl;
}


template <class T> 
void insertionSort(T* a, int size, BinaryRelation<T,T>& brel) {
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && brel.inRelation(a[j - 1], a[j])) {
			swap(a[j], a[j-1]);
			j--;
		}
	}
}



template <class T>
void quickSort(T* a, int left, int right, BinaryRelation<T,T>& brel) {
	int i = left;
	int j = right;
	while (j > i) {
		if (brel.inRelation(a[i] < a[i+1])) {
			swap(a[i + 1], a[j]);
			j--;
		} else {
			swap(a[i], a[i + 1]);
			i++;
		}
	}
	if (left < i - 1) quickSort(a, left, i - 1, brel);
	if (right > i + 1) quickSort(a, i + 1, right, brel);
}

template <class T>
void quickSort(T* a, int size, BinaryRelation<T,T>& brel) {
	quickSort(a, 0, size - 1, brel);
}



void countingSort(unsigned int* a, int size) {
	unsigned int max = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > max) max = a[i];
	}
	int* b = new int[max + 1];
	for (unsigned int i = 0; i <= max; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		b[a[i]]++;
	}
	int j = 0;
	for (unsigned int i = 0; i <= max; i++) {
		for (int k = 0; k < b[i]; k++) {
			a[j] = i;
			j++;
		}
	}
	delete[] b;
}




Color* getRandomColorArrayOfSize(int size) {
	Color* a = new Color[size];
	for (int i = 0; i < size; i++) {
		int r = rand() & 0xff;
		int g = rand() & 0xff;
		int b = rand() & 0xff;
		a[i] = Color(r, g, b);
	}
	return a;
}

unsigned int* getRandomIntArrayOfSize(int size) {
	unsigned int* a = new unsigned int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() & 0b1111;
	}
	return a;
}





int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
    
    // START YOUR TESTS HERE!
    
	return 0;
}