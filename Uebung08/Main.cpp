#include <iostream>

#include "ComplexNumber.h"
#include "..\src\ViewPortGL.h"
#include "..\Uebung07\Color.h"

using namespace std;

template <class T, class U>
void compute_sum(T a, U b) {
	ComplexNumber sum = a + b;
	cout << a << " + " << b << " = " << sum << endl;

	cout << a << " + " << b << " = ";
	a += b;
	cout << a << endl;
}

template <class T, class U>
void compute_diff(T a, U b) {
	ComplexNumber diff = a - b;
	cout << a << " - " << b << " = " << diff << endl;
}

template <class T, class U>
void compute_prod(T a, U b) {
	ComplexNumber prod = a * b;
	cout << a << " * " << b << " = " << prod << endl;
}

template <class T, class U>
void compute_div(T a, U b) {
	ComplexNumber quot = a / b;
	cout << a << " / " << b << " = " << quot << endl;
}

void compute_abs_value(ComplexNumber& a) {
	cout << "~" << a << " = " << ~a << endl;
}


unsigned int getMandelbrotIndex(ComplexNumber& x, double limes, int max) {
	ComplexNumber last(0, 0);
	ComplexNumber current(0, 0);

	for (int j = 0; j <= max; j++) {
		if (!current > limes) {
			return j;
		}
		current = last * last;
		current += x;
		last = current;
	}

	return max;
}

void drawMandelbrotMenge(ViewPortGL& vp) {
	int width = vp.getXSize();
	int height = vp.getYSize();
	double limes = 100;
	int max = 255;
	int n = 0;
	bool is_running = true;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			double compX = -2 + (3.0 / width * x);
			double compY = 1 - (2.0 / height * y);
			ComplexNumber pixel(compX, compY);
			n = getMandelbrotIndex(pixel, limes, max);

			if (n >= 255) {
				vp.preparePix(x, y, 0, 0, 0);
			}
			else {
				vp.preparePix(x, y, n, 0, n);
			}
		}
	}

	vp.sendPixels();
	vp.swapBuffers();
	
	while (is_running) {
		is_running = !vp.windowShouldClose();
		}
}


int main() {
	//Exercise 1
	ComplexNumber a(3, 5);
	ComplexNumber b(7, 2);
	ComplexNumber c(0, 1);

	compute_sum(a, b);
	compute_diff(a, b);
	compute_prod(c, c);
	compute_div(a, a);
	compute_diff(a, 3);
	compute_prod(4, a);
	compute_abs_value(a);

	ViewPortGL vp("Mandelbrotindex", 900, 600);
	drawMandelbrotMenge(vp);
}