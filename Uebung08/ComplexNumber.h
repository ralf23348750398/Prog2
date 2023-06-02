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
	double get_real() {
		return this->real;
	}
	double get_img() {
		return this->img;
	}
	void set_real(double real) {
		this->real = real;
	}
	void set_img(double img) {
		this->img = img;
	}
	void print(ComplexNumber& c) {
		cout << "(" << c.real << " + " << c.img << "i)";
	}
	template <class T>
	void print(T a) {
		cout << a;
	}
private:
	double real, img;
};

ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a.get_real() + b.get_real());
	res.set_img(a.get_img() + b.get_img());
	return res;
}

template <class T>
ComplexNumber operator+(ComplexNumber& a, T b) {
	ComplexNumber res;
	res.set_real(a.get_real() + b);
	res.set_img(a.get_img());
	return res;
}

template <class T>
ComplexNumber operator+(T a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a + b.get_real());
	res.set_img(b.get_img());
	return res;
}

ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a.get_real() - b.get_real());
	res.set_img(a.get_img() - b.get_img());
	return res;
}

template <class T>
ComplexNumber operator-(ComplexNumber& a, T b) {
	ComplexNumber res;
	res.set_real(a.get_real() - b);
	res.set_img(a.get_img());
	return res;
}

template <class T>
ComplexNumber operator-(T a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a - b.get_real());
	res.set_img(b.get_img());
	return res;
}

ComplexNumber operator*(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a.get_real() * b.get_real() - a.get_img() * b.get_img());
	res.set_img(a.get_real() * b.get_img() + a.get_img() * b.get_real());
	return res;
}

template <class T>
ComplexNumber operator*(ComplexNumber& a, T b) {
	ComplexNumber res;
	res.set_real(a.get_real() * b);
	res.set_img(a.get_img() * b);
	return res;
}

template <class T>
ComplexNumber operator*(T a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a * b.get_real());
	res.set_img(a * b.get_img());
	return res;
}

ComplexNumber operator/(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber res;
	double h = 1 / (pow(b.get_real(), 2) + pow(b.get_img(), 2));
	res.set_real(h * ((a.get_real() * b.get_real() + a.get_img() * b.get_img())));
	res.set_img(h * (a.get_img() * b.get_real() - a.get_real() * b.get_img()));
	return res;
}

template <class T>
ComplexNumber operator/(ComplexNumber& a, T b) {
	ComplexNumber res;
	res.set_real(a.get_real() / b);
	res.set_img(a.get_img() / b);
	return res;
}

template <class T>
ComplexNumber operator/(T a, ComplexNumber& b) {
	ComplexNumber res;
	res.set_real(a / b.get_real());
	res.set_img(a / b.get_real());
	return res;
}

ComplexNumber operator+=(ComplexNumber& a, ComplexNumber& b) {
	a.set_real(a.get_real() + b.get_real());
	a.set_img(a.get_img() + b.get_img());
	return a;
}

ComplexNumber operator-=(ComplexNumber& a, ComplexNumber& b) {
	a.set_real(a.get_real() - b.get_real());
	a.set_img(a.get_img() - b.get_img());
	return a;
}

ComplexNumber operator*=(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber original_a = a;
	a.set_real(a.get_real() * b.get_real() - a.get_img() * b.get_img());
	a.set_img(original_a.get_real() * b.get_img() + a.get_img() * b.get_real());
	return a;
}

ComplexNumber operator/=(ComplexNumber& a, ComplexNumber& b) {
	ComplexNumber original_a = a;
	double h = 1.0 / (pow(b.get_real(), 2) + pow(b.get_img(), 2));
	a.set_real(h * (a.get_real() * b.get_real() + a.get_img() * b.get_img()));
	a.set_img(h * (a.get_img() * b.get_real() - original_a.get_real() * b.get_img()));
	return a;
}

ostream& operator<<(ostream& os, ComplexNumber& a) {
	os << "(" << a.get_real() << " + " << a.get_img() << "i)";
	return os;
}

double operator~(ComplexNumber& a) {
	return sqrt(pow(a.get_real(), 2) + pow(a.get_img(), 2));
}

double operator!(ComplexNumber& a) {
	return sqrt(a.get_real() * a.get_real() + a.get_img() * a.get_img());
}