/**
 *
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 */


#include <bits/stdc++.h>
using namespace std;


void backtrack(vector<int> input, int k, int target, int idx, vector<int> arr, vector<vector<int>> &ans) {
	
	if (target < 0 && k < 0) return;
	
	// cout << "target = " << target << endl;
	if (target == 0 && k == 0) {
		ans.push_back(arr);
		return;
	}
	

	for (int i = idx; i < input.size(); i++) {
		if (i && i > idx && input[i] == input[i-1]) {
			continue;
		}
		arr.push_back(input[i]);
		backtrack(input, k - 1, target - input[i], i + 1, arr, ans);
		arr.pop_back();
	}
	
	return;
	
}

vector<vector<int>> sumCombination3(int n, int k){
	vector<vector<int>> ans;
	if (n == 0 || k == 0) return ans;
	
	vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> arr;
	backtrack(input, k, n, 0, arr, ans);
	return ans;
	
}

int main() {
	// your code goes here
	vector<vector<int>> ans = sumCombination3(7, 3);
	
	for (int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
