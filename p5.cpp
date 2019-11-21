/**
 * This problem was asked by Jane Street.
 * cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
 * For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
 */

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> cons(int a, int b) {
	return make_pair(a, b);
}

int car(pair<int, int> p) {
	return p.first;
}

int cdr(pair<int, int> p) {
	return p.second;
}

int main() {
	// your code goes here
	int a = 3, b = 4;
	cout << "FIRST = " << car(cons(3, 4)) << endl;
	cout << "SECOND = " << cdr(cons(3, 4)) << endl;
	
	
	return 0;
}
