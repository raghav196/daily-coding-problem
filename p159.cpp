/**
This problem was asked by Google.

Given a string, return the first recurring character in it, or null if there is no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.
 */

#include <bits/stdc++.h>
using namespace std;

char solve(string str) {
	
	set<char> hash;
	
	for (int i = 0; i < str.size(); i++) {
		if (hash.count(str[i])) {
			return str[i];
		}
		hash.insert(str[i]);
	}
	return '\0';

}


int main() {
	// your code goes here
	cout << solve("acbbac") << endl;
	cout << solve("abcdef") << endl;
	cout << solve("a") << endl;
	cout << solve("aaaaaab") << endl;
	return 0;
}
