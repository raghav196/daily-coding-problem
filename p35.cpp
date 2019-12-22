/**
 * This problem was asked by Google.
 * Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
 * Do this in linear time and in-place.
 * For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
 * 
 */

#include <bits/stdc++.h>
using namespace std;

char* solve(char str[100], int n) {
	
	int idx = 0;
	int left = 0, right = n - 1;
	
	while (idx <= right) {
		if (str[idx] == 'R') {
			swap(str[idx], str[left]);
			idx++;
			left++;
		} else if (str[idx] == 'G'){
			idx++;
		} else {
			swap(str[idx], str[right]);
			right--;
		}
	}
	return str;
}

int main() {
	// your code goes here
	
	char str[] = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	
	solve(str, 7);
	for (int i = 0; i < 7; i++) cout << str[i];
	cout << endl;
	return 0;
}
