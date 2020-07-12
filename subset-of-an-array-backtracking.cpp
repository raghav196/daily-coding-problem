#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void solve(vector<int> nums, int idx, vector<int> arr) {
	if (idx == nums.size()) {
		ans.push_back(arr);
		return;
	}
	// do not include current element
	solve(nums, idx+1, arr);
	
	// add current element
	arr.push_back(nums[idx]);
	solve(nums, idx+1, arr);
	
	return;
}


int main() {
	// your code goes here
	vector<int> nums = {1, 2, 3};
	vector<int> arr;
	solve(nums, 0, arr);
	
	for (auto v: ans) {
		for (auto ele: v) cout << ele << " ";
		cout << endl;
	}

	
	return 0;
}
