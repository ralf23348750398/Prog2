#pragma once

class ComplexNumber {
public:
	ComplexNumber(double real = 0, double imag = 0);
	//Copy-Constructor (not necessary here, as it is already there by default)
	ComplexNumber(const ComplexNumber& a);
	
	//operator overloading methods modifying the OLW (operator left value) -> definition inside the class
	ComplexNumber operator+=(const ComplexNumber& a);
	ComplexNumber operator-=(const ComplexNumber& a);

	//operator overloading methods resulting in a new object -> definition outside the class (friend/ getter & setter)
	friend ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b);
	friend ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b);

	//would be necessary if you defined the operator overloading functions outside the class without making use of the friend functionality
	double get_real();
	double get_imag();
private:
	double real, imag;
};

std::ostream& operator<<(std::ostream& os, ComplexNumber& c);
ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b);
ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b);