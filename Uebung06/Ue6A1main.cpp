#include "MyDouble.h"
#include "MyInt.h"
#include "beautifulFunction.cpp"
#include "FlexArray.h"


//1.a)
//double f(int x, double y) {
//	int var;
//	double z = y.compute(x);
//	for (int i = 0; i < var; i++) {
//		z = z.compute(y, z);
//	}
//	return z;
//}

//1.b)
//template<class S, class T, int var>
//S f(T x, S y) {
//	S z = y.compute(x);
//	for (int i = 0; i < var; i++) {
//		z = z.compute(y, z);
//	}
//	return z;
//}

int main() {
	//1.a)
	/*Die Realisierung ist nicht korrekt, da y ein Objekt einer bestimmten Klasse sein müsste,
	da mit y.compute(x) eine Methode eines Objekts aufgerufen wird.*/

	//1.b)
	/*Error: "Expression must have class type but it has type double."*/

	//1.c)
	/*MyDouble d1 = MyDouble();
	MyInt i1 = MyInt();
	f<MyDouble, MyInt, 5>(i1, d1);*/

	//Exercise 2
	//int array
	FlexArray <int, 2, 5>f1(0);
	f1.print();
	int x = 0;
	for (int i = 0; i < 11; i++) {
		f1.set(i, ++x);
	}
	f1.print();
	cout << "value at given position: " << f1.get(33) << endl << endl;
	f1.print();
	f1.exchange(2, 66);
	f1.print();

	//double array
	/*FlexArray <double, 2, 5>f1(0.0);
	f1.print();
	double x = 0.234;
	for (int i = 0; i < 11; i++) {
		f1.set(i, ++x);
	}
	f1.print();
	cout << "value at given position: " << f1.get(33) << endl << endl;
	f1.print();
	f1.exchange(2, 66);
	f1.print();*/

	//string array
	/*FlexArray <std::string, 2, 5>f1("");
	f1.print();
	for (int i = 0; i < 11; i++) {
		f1.set(i, "test");
	}
	f1.print();
	cout << "value at given position: " << f1.get(33) << endl << endl;
	f1.print();
	f1.exchange(2, 66);
	f1.print();*/
}