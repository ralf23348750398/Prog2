#include <iostream>

using namespace std;

int fac_rec(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * fac_rec(n - 1);
	}
}

int fac_iter(int n) {
	if (n == 0) {
		return 1;
	}
	int result = 0;
	int prev = 1;

	for (int i = 1; i <= n; i++) {
		result = i * prev;
		prev = result;
	}
	return result;
}

int fibo_rec(int n) {
	if (n <= 2) {
		return 1;
	}
	return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int fibo_iter(int n) {
	if (n <= 2) {
		return 1;
	}
	int result = 0;
	int prev1 = 1;
	int prev2 = 1;

	for (int i = 3; i <= n; i++) {
		result = prev1 + prev2;
		prev2 = prev1;
		prev1 = result;
	}
	return result;
}

int aud_2_5_rec(int n) {
	if (n <= 2) {
		return 1;
	}
	else {
		return n + aud_2_5_rec(n - 2);
	}
}

int aud_2_5_iter(int n) {
	if (n <= 2) {
		return 1;
	}

	int result = 0;
	int prev1 = 1;
	int prev2 = 1;

	for (int i = 3; i <= n; i++) {
		result = i + prev2;
		prev2 = prev1;
		prev1 = result;
	}

	return result;
}

double aud_3_8_rec(double n) {
	if (n <= 1) {
		return 1;
	}
	return (1.0 / n) + aud_3_8_rec(n - 1);
}

double aud_3_8_iter(int n) {
	if (n <= 1) {
		return 1;
	}

	double result = 0;
	double prev = 1;

	for (int i = 2; i <= n; i++) {
		result = 1.0 / i + prev;
		prev = result;
	}
	return result;
}

int prog_132_iter(int start, int end) {
	int s = 0;
	while (start <= end) {
		s = s + start;
		start++;
	}
	return s;
}

int prog_132_rec(int start, int end) {
	if (start <= end) {
		return start + prog_132_rec(start+1, end);
	}
	else {
		return 0;
	}
}

int main() {
	cout << fac_rec(4) << endl;
	cout << fac_iter(4) << endl;

	cout << fibo_rec(10) << endl;
	cout << fibo_iter(10) << endl;

	cout << aud_2_5_rec(6) << endl;
	cout << aud_2_5_iter(6) << endl;

	cout << aud_3_8_rec(3) << endl;
	cout << aud_3_8_iter(3) << endl;

	cout << prog_132_iter(4, 7) << endl;
	cout << prog_132_rec(4, 7) << endl;
	return 0;
}