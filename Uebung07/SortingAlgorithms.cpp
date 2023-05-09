
#include <iostream>
#include <algorithm>
#include <string>
#include "BinaryRelation.h"
#include "Color.h"
#include "InOrderIntRelation.h"
#include "ReverseOrderIntRelation.h"
#include "ColorRelationColor.h"
#include "ColorRelationBrightness.h"

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
void insertionSort(T* a, int size, BinaryRelation<T, T>& rel) {
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 &&	rel.inRelation(a[j], a[j-1])) {
			swap(a[j], a[j-1]);
			j--;
		}
	}
}



template <class T>
void quickSort(T* a, int left, int right, BinaryRelation<T, T>& rel) {
	int i = left;
	int j = right;
	while (j > i) {
		if (rel.inRelation(a[i], a[i+1])) {
			swap(a[i + 1], a[j]);
			j--;
		} else {
			swap(a[i], a[i + 1]);
			i++;
		}
	}
	if (left < i - 1) quickSort(a, left, i - 1, rel);
	if (right > i + 1) quickSort(a, i + 1, right, rel);
}

template <class T>
void quickSort(T* a, int size, BinaryRelation<T, T>& rel) {
	quickSort(a, 0, size - 1, rel);
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

void e_7b() {
	cout << "Exercise 7b) - InOrder: " << endl;

	InOrderIntRelation& rel = InOrderIntRelation::get_Instance();
	int size = 10;

	unsigned int* int_arr1 = getRandomIntArrayOfSize(size);
	cout << "Unsorted array: " << endl;
	printArray(int_arr1, size);

	insertionSort(int_arr1, size, rel);
	cout << endl << "Sorted array (Insertion Sort):" << endl;
	printArray(int_arr1, size);

	unsigned int* int_arr2 = getRandomIntArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(int_arr2, size);
	quickSort(int_arr2, size, rel);
	cout << endl << "Sorted array (Quicksort):" << endl;
	printArray(int_arr2, size);

}

void e_7c() {
	cout << endl << "Exercise 7c) - ReverseOrder: " << endl;

	ReverseOrderIntRelation& ro_rel = ReverseOrderIntRelation::get_Instance();
	int size = 10;

	unsigned int* int_arr3 = getRandomIntArrayOfSize(size);
	cout << "Unsorted array: " << endl;
	printArray(int_arr3, size);
	insertionSort(int_arr3, size, ro_rel);
	cout << endl << "Sorted array (Insertion Sort):" << endl;
	printArray(int_arr3, size);

	unsigned int* int_arr4 = getRandomIntArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(int_arr4, size);
	quickSort(int_arr4, size, ro_rel);
	cout << endl << "Sorted array (Quicksort):" << endl;
	printArray(int_arr4, size);
}

void e_7d_color() {
	cout << endl << "Exercise 7d - color: " << endl;
	ColorRelationColor& co_rel = ColorRelationColor::get_Instance();
	int size = 5;

	Color* color_arr1 = getRandomColorArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(color_arr1, size);
	insertionSort(color_arr1, size, co_rel);
	cout << endl << "Sorted array (Insertion Sort):" << endl;
	printArray(color_arr1, size);

	Color* color_arr2 = getRandomColorArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(color_arr2, size);
	quickSort(color_arr2, size, co_rel);
	cout << endl << "Sorted array (Quicksort):" << endl;
	printArray(color_arr2, size);
}

void e_7d_brightness() {
	cout << endl << "Exercise 7d - brightness:" << endl;
	ColorRelationBrightness& co_rel = ColorRelationBrightness::get_Instance();
	int size = 5;
	
	Color* color_arr1 = getRandomColorArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(color_arr1, size);
	insertionSort(color_arr1, size, co_rel);
	cout << endl << "Sorted array (Insertion Sort):" << endl;
	printArray(color_arr1, size);

	Color* color_arr2 = getRandomColorArrayOfSize(size);
	cout << endl << "Unsorted array: " << endl;
	printArray(color_arr2, size);
	quickSort(color_arr2, size, co_rel);
	cout << endl << "Sorted array (Quicksort):" << endl;
	printArray(color_arr2, size);
}

template <class T>
void sort(T* arr, int size, BinaryRelation<T, T>& rel) {
	cout << endl << "Unsorted array: " << endl;
	printArray(arr, size);

	if (std::is_unsigned<T>::value) {
		countingSort(arr, size);
		cout << endl << "Sorted array (Counting Sort):" << endl;
	}
	else if (size <= 16) {
		insertionSort(arr, size, rel);
		cout << endl << "Sorted array (Insertion Sort):" << endl;
	}
	else {
		quickSort(arr, size, rel);
		cout << endl << "Sorted array (Quicksort):" << endl;
	}

	printArray(arr, size);
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	//Exercise 7 b)
	e_7b();

	//Exercise 7 c)
	e_7c();

	//Exercise 7 d)
	e_7d_color();
	e_7d_brightness();

	//Exercise 8
	cout << endl << "Exercise 8:" << endl;
	InOrderIntRelation& io_rel = InOrderIntRelation::get_Instance();
	int size = 17;
	unsigned int* int_arr = getRandomIntArrayOfSize(size);
	sort(int_arr, size, io_rel);

	return 0;
}