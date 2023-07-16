#include <iostream>
#include <bitset>

using namespace std;


class A {};
class B : public A {};
long f(long x) {
	throw B();
}
void main() {
	long x = 7;
	try {
		cout << "f(" << x << ") ist " << f(x) << endl;
	}
	catch (A x) {
		cout << "A" << endl;
	}
	catch (B x) {
		cout << "B" << endl;
	}
}