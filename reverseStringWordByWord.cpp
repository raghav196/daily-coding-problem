/**
 * 
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.
 */

#include <iostream>
using namespace std;

string solve(string A) {
	
	int end = A.size() - 1;
	while (end >= 0 && A[end] == ' ') {
		end--;
	}
	
	int start;
	string ans;
	for (int i = end; i >= 0; ) {
		end = i;
		while (i >= 0 && A[i] != ' ') {
			i--;
		}
		start = i+1;
		ans += A.substr(start, end - start + 1);
		
		while (i >= 0 && A[i] == ' ') {
			i--;
		}
		
		if (i >= 0) {
			ans += " ";
		}
		
		
	}
	return ans;
	
}


int main() {
	// your code goes here
	cout << solve("this is ib") << endl;
	cout << solve("j") << endl;
	cout << solve("     this      is ib     ") << endl;
	return 0;
}
