/**
 *
This problem was asked by Google.
Given two strings A and B, return whether or not A can be shifted some number of times to get B.
For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
 */

#include <bits/stdc++.h>
using namespace std;

string rotateString(string str) {
	char t = str[0];
	for (int i = 1; i < str.size(); i++) {
		str[i-1] = str[i];
	}
	str[str.size() - 1] = t;
	return str;
}

int solve(string A, string B) {
	if (A.size() != B.size()) return 0;
	
	string newString = rotateString(A);
	cout << "1st " << newString << endl;
	if (newString == B) return 1;
	
	while (newString != A) {
		newString = rotateString(newString);
		cout << "inloop " << newString << endl;
		if (newString == B) return 1;
	}
	return 0;
	
}

/**
 * Concatenate A with A. temp = A + A.
 * Now, if B is a substring in temp, then A can be rotated to obtain B, else no.
 * 
 */
int solve2(string A, string B) {
	if (A.size() != B.size()) return 0;
	
	string temp = A + A;
	cout << "temp = " << temp << endl;
	
	if (temp.find(B) != string::npos) return 1;
	else return 0;
	
	
}

int main() {
	// your code goes here
	cout << solve2("abcde", "cdeab") << endl;
	cout << solve2("abc", "acb") << endl;
	return 0;
}
