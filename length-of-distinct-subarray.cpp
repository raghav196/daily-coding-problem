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
	
	for (int i = 0; i < arr.size(); i++) {
		auto it = hash.find(arr[i]);
		if (it != hash.end()) { // found
			start = max(start, it->second + 1);
			// start = max(start, it->second);
		}
		hash[arr[i]] = i;
		ans = max(ans, i - start + 1);
	}
	
	// time complexity = O(2n), as in the worst case each element would be visited twice
	// int i = 0;
	// while (i < arr.size() && start < arr.size()) {
	// 	auto it = hash.find(arr[i]);
	// 	if (it == hash.end()) {
	// 		hash[arr[i]] = 1;
	// 		i++;
	// 		ans = max(ans, i-start);
	// 	} else {
	// 		hash.erase(arr[start]);
	// 		start++;
	// 	}
	// }
	
	
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
