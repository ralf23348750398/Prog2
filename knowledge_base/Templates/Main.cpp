#include <iostream>

#include "Template.h"

using namespace std;

template <class T>
T compute_avg(T a, T b) {
	return (a + b) / 2;
}

template<> //template specialization - used for optimizing algorithms or as in this case generally different computation for the given parameters (here: int*)
int* compute_avg<int*>(int* a, int* b) {
	int res = 0;
	int* ptr_res = &res;
	*ptr_res = (*a + *b) / 2;
	return ptr_res;
}

//default parameters
template <class T=int, class S=double>
class Pair {
public:
	Pair(T p1, S p2) {
		this->p1 = p1;
		this->p2 = p2;
	}
	T getFirst() {
		return p1;
	}
	S getSecond();
private:
	T p1;
	S p2;
};

//method definition outside of the class scope
template<class T, class S>
S Pair<T, S>::getSecond() {
	return p2;
}

int main() {
	cout << compute_avg(2.2, 3.3) << endl;
	cout << compute_avg(1, 3) << endl;

	int a = 5, b = 3;
	int* ptr_a = &a;
	int* ptr_b = &b;
	cout << *compute_avg<int*>(ptr_a, ptr_b) << endl;
	cout << endl;

	//object creation specifying the template parameters
	Pair<double, int> p1(3.4, -4);
	cout << p1.getFirst() << endl;
	cout << endl;

	//object creation using the default template parameters
	Pair<> p2(3.2, -5);
	cout << p2.getSecond() << endl;

	myFancyArray<int, 10> a1(0);
	cout << a1.get(2) << endl;
	a1.set(23, 2);
	cout << a1.get(2) << endl;
}