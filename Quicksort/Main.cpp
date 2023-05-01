#include <iostream>

using namespace std;


int partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int l = low, r = high - 1;

	while (l < r) {
		while (l < high && arr[l] < pivot) {
			l++;
		}
		while (r > low && arr[r] >= pivot) {
			r--;
		}
		if (l < r) {
			swap(arr[l], arr[r]);
		}
	}
	if (arr[l] > pivot) {
		swap(arr[l], arr[high]);
	}
	return l;
}

void quicksort_recursive(int* arr, int l, int r) {
	if (l < r) {
		int divider = partition(arr, l, r);
		quicksort_recursive(arr, l, divider - 1);
		quicksort_recursive(arr, divider + 1, r);
	}
}

int main()
{
	const int length = 10;
	int left_index = 0, right_index = length - 1;
	int arr[length] = { 5, 18, 64, 12, 1, 6, 1, 8, 2, 10 };

	cout << "Unsorted array: " << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	quicksort_recursive(&arr[0], left_index, right_index);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}