/**
 * This problem was asked by Uber.
 * Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 * Follow-up: what if you can't use division?
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force. But will if any of the element is zero.
 */
vector<int> solve(vector<int> &arr) {
	vector<int> result;
	
	int prod = 1;
	for (int i = 0; i < arr.size(); i++) {
		prod *= arr[i];
	}
	
	for (int i = 0; i < arr.size(); i++) {
		result.push_back(prod / arr[i]);
	}
	return result;
	
}

/**
 * Algorithm:
 * Take a left array in which left[i] = product of all elments till i excluding arr[i].
 * Take a right array in which right[i] contains product of all element on right of arr[i] excluding arr[i]
 * For ans[i] = left[i] * right[i]
 * time complexity = O(n)
 * space complexity = O(n + n) = O(n)
 */ 
vector<int> solve2(vector<int> &arr) {
	
	// check for base case.
	if (arr.size() == 0 || arr.size() == 1) {
		return vector<int>();
	}
	
	vector<int> result;
	
	int n = arr.size();
	vector<int> left(n);
	vector<int> right(n);
	
	left[0] = 1;
	right[n - 1] = 1;
	
	// populate left array
	for(int i = 1; i < n; i++) {
		left[i] = left[i-1] * arr[i-1];
	}
	
	// popultae right array
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i+1] * arr[i+1];
	}
	
	for (int i = 0; i < n; i++) {
		result.push_back(left[i] * right[i]);
	}
	
	return result;
	
}


int main() {
	// your code goes here
	
	vector<int> arr = {2, 5, 1, 0}; // {3, 2,1 }; //{1, 2, 3, 4, 5}; // {1};
	// vector<int> result = solve(arr);
	
	vector<int> result = solve2(arr);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	
	cout << endl;
	return 0;
}
