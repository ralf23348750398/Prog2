#pragma once

#include <iostream>

using namespace std;

class ComplexNumber {
public:
	ComplexNumber(double real, double img) {
		this->real = real;
		this->img = img;
	}
	ComplexNumber() {
		this->real = 0;
		this->img = 0;
	}
	friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
		ComplexNumber res;
		res.real = a.real + b.real;
		res.img = a.img + b.img;
		return res;

	}
	void print(ComplexNumber& c) {
		cout << c.real << " + " << c.img << "i";
	}
private:
	double real, img;
};
