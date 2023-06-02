#include <iostream>
#include "ComplexNumber.h"

using namespace std;

template <class T, class U>
void compute_sum(T a, U b) {
	ComplexNumber sum = a + b;
	sum.print(a);
	cout << " + ";
	sum.print(b);
	cout << " = ";
	sum.print(sum);
	cout << endl;

	a.print(a);
	cout << " + ";
	a.print(b);
	cout << " = ";
	a += b;
	a.print(a);
	cout << endl;
}

template <class T, class U>
void compute_diff(T a, U b) {
	ComplexNumber diff = a - b;
	diff.print(a);
	cout << " - ";
	diff.print(b);
	cout << " = ";
	diff.print(diff);
	cout << endl;
}

template <class T, class U>
void compute_prod(T a, U b) {
	ComplexNumber prod = a * b;
	prod.print(a);
	cout << " * ";
	prod.print(b);
	cout << " = ";
	prod.print(prod);
	cout << endl;

	a.print(a);
	cout << " * ";
	a.print(b);
	cout << " = ";
	a *= b;
	a.print(a);
	cout << endl;
}

template <class T, class U>
void compute_div(T a, U b) {
	ComplexNumber quot = a / b;
	quot.print(a);
	cout << " / ";
	quot.print(b);
	cout << " = ";
	quot.print(quot);
	cout << endl;

	quot.print(a);
	cout << " / ";
	quot.print(b);
	cout << " = ";
	a += b;
	quot.print(a);
	cout << endl;
}


unsigned int getMandelbrotIndex(ComplexNumber& x, double limes, int max) {
	ComplexNumber m(0,0);
	for (int j = 0; j < max; j++) {
		m = m * m;
		m = m + x;

		if (abs(x.get_real()) > limes || abs(x.get_img()) > limes) {
			return j;
		}
	}
	return max;
}


int main() {
	ComplexNumber a(3, 5);
	ComplexNumber b(7, 2);
	compute_sum(a, b);
	compute_diff(a, b);

	ComplexNumber c(0, 1);
	compute_prod(c, c);
	compute_div(a, a);

	compute_diff(a, 3);
	//compute_prod(4, a);
}