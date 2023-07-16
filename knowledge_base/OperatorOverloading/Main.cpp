#include <iostream>
#include "ComplexNumber.h"

using namespace std;


int main() {
	ComplexNumber a(5, 3);
	ComplexNumber b(2, 4);

	ComplexNumber c = a + b;
	cout << a << " + " << b << " = " << c << endl;

	c = a - b;
	cout << a << " - " << b << " = " << c << endl;

	ComplexNumber d = c;
	cout << d << " = " << c << endl;

	return 0;
}