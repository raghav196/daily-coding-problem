/**
 *
This problem was asked by Google.
Given a sorted list of integers, square the elements and give the output in sorted order.
For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr) {
	if (arr.size() == 0) return vector<int>();
	
	int n = arr.size();
	vector<int> ans(n);
	
	int low = 0, high = n - 1;
	int k = n - 1;
	
	while (low <= high) {
		int leftVal = arr[low] * arr[low];
		int rightVal = arr[high] * arr[high];
		
		if (leftVal <= rightVal) {
			ans[k--] = rightVal;
			high--;
		} else {
			ans[k--] = leftVal;
			low++;
		}
	}
	return ans;
}


int main() {
	// your code goes here
	vector<int> arr = {-9, -2, 0, 2, 3};
	vector<int> ans = solve(arr);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	
	arr = {-9};
	ans = solve(arr);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	
	arr = {-9, -2, 0, 2, 3, 10};
	ans = solve(arr);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
