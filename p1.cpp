/**
 * This problem was recently asked by Google.
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 * Bonus: Can you do this in one pass?
 */

#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &arr, int k) {
	sort(arr.begin(), arr.end());
	int low = 0, high = arr.size() - 1;
	while (low < high) {
		int temp = arr[low] + arr[high];
		if (temp == k) {
			return true;
		} else if (temp < k) {
			low++;
		} else {
			high--;	
		}
	}
	return false;
}


bool solveUsingHashMap(vector<int> &arr, int k) {
	unordered_map<int, int> hash;
	
	for (int i = 0; i < arr.size(); i++) {
		if (hash.find(arr[i]) != hash.end()) {
			return true;
		}
		hash.insert(make_pair(k-arr[i], i));
	}
	return false;
}


int main() {
	// your code goes here
	
	vector<int> arr = {10, -5, 12, 3};
	int k = 5;
	cout << "ANS = " << solve(arr, k) << endl;
	cout << "ANS 2 = " << solveUsingHashMap(arr, k) << endl;
	
	return 0;
}
