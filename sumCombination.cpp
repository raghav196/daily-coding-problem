/**
 * Given a positive number n, and a array of positive numbers arr[].
 * Find the all the possible sum combinations of n by choosing the elements from arr.
 * Note: You can repeat the array element any number of times.
 */

#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl;
}

void findAllPossiblePaths(int n, vector<int> arr, vector<int> path) {
	if (n < 0) {
		return;
	}
	
	if (n == 0) {
		printPath(path);
		return;
	}
	
	for (int i = 0; i < arr.size(); i++) {
		path.push_back(arr[i]);
		findAllPossiblePaths(n - arr[i], arr, path);
		path.pop_back();
	}
}


int main() {
	// your code goes here
	int  n = 4;
	vector<int> arr = {1, 2, 3};
	vector<int> path;
	cout << "-------------------\n";
	findAllPossiblePaths(n, arr, path);
	cout << "-------------------\n";
	return 0;
}
