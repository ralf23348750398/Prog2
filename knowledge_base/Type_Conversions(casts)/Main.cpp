#include <iostream>

using namespace std;

class Base {
public: 
	Base() {
		cout << "Base class constructor called" << endl;
	}
	virtual void call_me() {
		cout << "Called method of base class" << endl;
	}
	void call_base() {
		cout << "Explicitly called base class method" << endl;
	}
private:
	
};

class Derived :public Base {
public:
	Derived() {
		cout << "Derived class constructor called" << endl;
	}
	void call_me() {
		cout << "Called method of derived class" << endl;
	}
	void call_derived() {
		cout << "Explicitly called derived class method" << endl;
	}
private:
	
};

void implicit_type_conversion() {
	char x = 7;		//Typumwandlung int -> char
	float y = 9.99;		//Typumwandlung double -> float (should be avoided)
	double z = (x * 1) + y;		//Typumwandlung char -> int, int -> float, float -> double
	cout << z << endl;

	char a = 4;
	char b = 'd';
	int c = a + b;
	cout << c << endl;
}

void explicit_type_conversions() {
	char d = 4;		//int -> char
	int e = static_cast<int>(d);	//char -> int
	double f = static_cast<float>(d);	//char -> float -> double
	double k = (int)d;	//char -> int -> double

	const int g = 4.4;		//double -> int
	int& h = const_cast<int&>(g);	//remove constness to modify g (should be avoided)
	cout << h << endl;	//4
	int* i = const_cast<int*>(&g);

	h += 4;
	cout << h << endl;	//8

	*i += 1;

	cout << h << endl;	//9
	cout << *i << endl;	//9
	cout << g << endl;	//4

	float* n = new float(4.4f);
	//int* o = static_cast<int*>(n);	//not working, cause int* is at the same pointer hierarchy level as float*
										//void* -> int* would work
}

void g(int i) {

}

void f(double d) {

}

class I {
public:
	I(int x) {}
	I(){
		cout << "Default constructor called. " << endl;
	}
};
class D {
public:
	D(double x){}
};

int main() {	
//testing
	int i = 4;
	double d = 5.5;
	I a(d);
	I(static_cast<int>(d));
	I();
	//I(d);		//not possible
	//I(i);		//not possible

	Derived derivedobj;
	Base* baseobj = &derivedobj;

	derivedobj.call_me();	//calling the derived class method
	baseobj->call_me();		//calling the derived class method

	Base* myobj = new Derived();
	myobj->call_me();		//calling the derived class method

//upcasts (derived obj treated as base obj)
	Derived derived;
	Base b1 = derived;						//implicit upcast
	Base b2 = static_cast<Base>(derived);	//explicit upcast
	derived.call_me();	//calling the derived class method
	b1.call_me();		//calling the base class method
	b2.call_me();		//calling the base class method

//downcast (base object treated as a derived object) - only working with dynamic_cast
	Base* b3 = new Derived();	//downcasts only work with objects that actually are derived class objects but currently treated as base class objects
	Derived* derivedPtr = dynamic_cast<Derived*>(b3);
	if (derivedPtr) {
		// The downcast was successful
	}
	else {
		// The downcast failed, basePtr does not actually point to a Derived object
	}

	b3->call_me();			//calling the derived class method
	derivedPtr->call_me();	//calling the derived class method
	
//explicit downcast with reinterpret_cast (should be avoided)
	Base base;
	Derived* deriv = reinterpret_cast<Derived*>(&base);

	deriv->call_me();		//calling base class method
	deriv->call_base();		//working just fine
	deriv->call_derived();	//working just fine as well


//explicit & implicit type conversions of simple data types
	explicit_type_conversions();
	//implicit_type_conversion();

//expected data type of functions
	double l = 3.4;
	int m = 3;

	//g(int{ l });	//the value of the double variable l is passed as an argument to a function g that takes an int parameter, hence resulting in an error
	//f(double{ m });	//not working, as there might be a loss of information
	g(int{ static_cast<int>(l) });	//working fine as l is converted to an integer value
	g(l);		//implicit conversion
	f(m);		//implicit conversion


	return 0;
}