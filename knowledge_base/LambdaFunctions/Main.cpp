#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int add(int x, int y) {
	return x + y;
}

int mult(int x, int y) {
	return x * y;
}

//making use of function pointers to decide which function to execute
int selector_c_style(bool select, int x, int y) {
	//defining func as a function variable (old C style) - The difference to normal functions is, that function variables can be modified and are therefore no rvalues
	int (*func)(int, int);
	select? func = add: func = mult;
	return func(x, y);
}

int selector_cplusplus_style(bool select, int x, int y) {
	//using std::function (recommended)
	function<int(int, int)> func;
	select ? func = add : func = mult;
	return func(x, y);
}

bool strcomp(const string& a, const string& b) {
	return a.length() < b.length();
}

void output_vec(vector<string>& vec) {
	for (const string& word : vec) {
		cout << word << " ";
	}
	cout << endl;
}

void wordsort() {
	//std::sort using a lambda function
	vector<string> words = { "apple", "banana", "cherry", "date" };
	output_vec(words);

	sort(words.begin(), words.end(),//lambda function capturing no lokal variables [] but taking two parameters as input, therefore comparing the strings based on their length
									[](const string& a, const string& b) 
									{return a.length() < b.length(); }		);
	output_vec(words);

	//std::sort using a normal function
	vector<string> words2 = { "apple", "banana", "cherry", "date" };
	output_vec(words2);

	sort(words2.begin(), words2.end(), strcomp);
	output_vec(words2);
}

int main() {
	cout << selector_c_style(0, 5, 4) << endl;
	cout << selector_cplusplus_style(1, 5, 4) << endl;

	wordsort();

	return 0;
}