#include <iostream>

using namespace std;

int recursive(double n, int count, unsigned long long stop) {
	if (n < stop) {
		return recursive(2*n, count++, stop);
	}
	return count;
}

int iterative(double n, unsigned long long stop) {
	
}

int main()
{
	double n = 0;
	int count = 0;
	unsigned long long stop = 0;

	cout << "Papierdicke in mm: " << endl;
	cin >> n;
	cout << "Strecke in mm: " << endl;
	cin >> stop;
	cout << "Anzahl an noetigen Faltvorgaengen: " << recursive(n, count, stop) << endl;

}













// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
