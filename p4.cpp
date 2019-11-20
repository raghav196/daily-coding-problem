/**
 * This problem was asked by Stripe.
 * Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 * For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
 * You can modify the input array in-place.
 */

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
	
	int idx = 0;
	while(idx < arr.size()) {
		// check if an element is at its correct position. if not swap it with its correct place.
		if (arr[idx] > 0 && arr[idx] < arr.size() && arr[idx] != arr[arr[idx] - 1]) {
			swap(arr[idx], arr[arr[idx] - 1]);
		} else {
			idx++;
		}
	}
	
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	
	return arr.size();
	
}


int main() {
	// your code goes here
	
	vector<int> arr = {3, 4, -1, 1};
	cout << "ANS = " << solve(arr);
	return 0;
}
