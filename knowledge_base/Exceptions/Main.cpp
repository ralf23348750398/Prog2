#include <iostream>
#include <string>

using namespace std;

double sqrt1(double n) {
	if (n < 0) {
		//throw "You cannot calculate the square root of " + to_string(n) + " as it is a negative value.";
		//throw "You cannot calculate the square root of a negative number";
		throw n;
	}
	return sqrt(n);
}

void exception_handler_basic_data_types() {
	try {
		sqrt1(-4);
	}
	catch (string msg) {
		cout << "Exception thrown: " << msg << endl;
	}
	catch (const char* msg) {
		cout << "Exception thrown: " << msg << endl;
	}
	catch (double value) {
		cout << value << endl;
	}
}

double sqrt2(double n) {
	if (n < 0) {
		//throw runtime_error("Need a positive number. " + to_string(n) + " is the specified number.");
		throw invalid_argument("Need a positive number. " + to_string(n) + " is the specified number.");

	}
	return sqrt(n);
}


void exception_handler_standard_exceptions() {
	try {
		sqrt2(-5);
	}
	catch (runtime_error rte) {
		cout << "Runtime_error block: " << rte.what() << endl;
	}
	catch (exception ex) {
		cout << "Exception block: " << ex.what() << endl;
	}
	catch (invalid_argument inva) {
		cout << "Invalid_argument block: " << inva.what() << endl;
	}
}

class A{};
class B:public A{};

int f(int n) {
	throw B();
	return n;
}

class MyException :public exception {
private:
	string message;
public:
	MyException(const string &msg) {
		this->message = msg;
	}
	const char* what() {
		return message.c_str();
	}
};

int g(int n) {
	throw MyException("Falsche Eingabe: " + to_string(n));
}

void exception_handler_classes() {
	try {
		f(5);
	}
	catch (A x) {
		cout << "A" << endl;
	}
	catch (B x) {
		cout << "B" << endl;
	}

	try {
		g(5);
	}
	catch (MyException e) {
		cout << e.what() << endl;
	}
}

int main() {
	try {
		exception_handler_basic_data_types();
		exception_handler_standard_exceptions();
		exception_handler_classes();
	}
	catch (...) {	//catches exceptions of all types - not recommended!	

	}
	return 0;
}