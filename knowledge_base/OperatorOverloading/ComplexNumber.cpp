#include <iostream>
#include "ComplexNumber.h"


ComplexNumber::ComplexNumber(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

//Copy-Constructor (not necessary here, as it is already there by default)
ComplexNumber::ComplexNumber(const ComplexNumber& a) {
	this->imag = a.imag;
	this->real = a.real;
}

double ComplexNumber::get_imag() {
	return this->imag;
}

double ComplexNumber::get_real() {
	return this->real;
}

//making use of the friend keyword -> accessing private member variables (should be avoided - better use getter & setter methods)
ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b) {
	return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

//making use of the friend keyword -> accessing private member variables (should be avoided - better use getter & setter methods)
ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b) {
	return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber ComplexNumber::operator+=(const ComplexNumber& a) {
	this->imag += a.imag;
	this->real += a.real;
	return *this;
}

ComplexNumber ComplexNumber::operator-=(const ComplexNumber& a) {
	this->real -= a.real;
	this->imag -= a.imag;
	return *this;
}

std::ostream& operator<<(std::ostream& os, ComplexNumber& a) {
	os << "(" << a.get_real() << " + " << a.get_imag() << "i)";
	return os;
}