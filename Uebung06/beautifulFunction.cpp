#include "MyDouble.h"
#include "MyInt.h"

template<class S, class T, int var>
S f(T x, S y) {
	S z = y.compute(x);
	for (int i = 0; i < var; i++) {
		z = z.compute(y, z);
	}
	return z;
}