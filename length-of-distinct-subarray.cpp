/**

Given an array of elements, return the length of the longest subarray where all its elements are distinct.
For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].

 */

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
	if (arr.size() == 0) return 0;
	
	unordered_map<int, int> hash;
	int ans = 0;
	int start = 0;
	
	int i = 0;
	while (i < arr.size() && start < arr.size()) {
		auto it = hash.find(arr[i]);
		if (it == hash.end()) {
			hash[arr[i]] = 1;
			i++;
			ans = max(ans, i-start);
		} else {
			hash.erase(arr[start]);
			start++;
		}
	}
	
	
	return ans;
}



int main() {
	// your code goes here
	vector<int> arr = {5, 1, 3, 5, 2, 3, 4, 1};
	cout << "ans = " << solve(arr) << endl;
	
	arr = {1, 1, 1, 1};
	cout << "ans = " << solve(arr) << endl;
	
	arr = {1, 2, 3, 4};
	cout << "ans = " << solve(arr) << endl;
	return 0;
}
