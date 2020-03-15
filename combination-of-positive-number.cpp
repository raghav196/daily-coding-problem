/**
 * Given a positive number, find out all combinations of positive numbers that adds upto that number.
 * The program should print only combinations, not permutations.
 * For example, for input 3, either 1, 2 or 2, 1 should be printed.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> input, int target, int idx, vector<int> arr, vector<vector<int>> &ans) {
	if (target < 0) return;
	
	if (target == 0 && k == 0) { 
		ans.push_back(arr);
		return;
	}
	
	/**
	 * If we need to form sets of size k 
	 */
	// if (target == 0 && k == 0) { 
	// 	ans.push_back(arr);
	// 	return;
	// }
	
	for (int i = idx; i < input.size(); i++) {
		arr.push_back(input[i]);
		backtrack(input, target - input[i], i, arr, ans);
		// backtrack(input, target - input[i], i+1, arr, ans); // can't reuse elements
		// backtrack(input, target - input[i], i, k-1, arr, ans); // form sets of size k
		arr.pop_back();
	}
	return;
}


vector<vector<int>> combine(int n) {
	vector<vector<int>> ans;
	if (n == 0) return ans;
	
	vector<int> input;
	for (int i = 0; i < n; i++) {
		input.push_back(i+1);
	}
	
	vector<int> arr;
	backtrack(input, n, 0, arr, ans);
	// backtrack(input, n, 0, k, arr, ans); // form sets of size k
	return ans;
	
}


int main() {
	// your code goes here
	vector<vector<int>> ans = combine(5);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
