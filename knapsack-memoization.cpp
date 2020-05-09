/**
 * 0-1 Knapsack. Recusrive solution
 */


#include <bits/stdc++.h>
using namespace std;

int backtrack(vector<int> &wts, vector<int> &profits, int idx, int capacity) {
	
	if (capacity <= 0 || idx >= wts.size()) {
		return 0;
	}
	
	// int profit1 = 0;
	if (wts[idx] <= capacity) {
		return max(profits[idx] + backtrack(wts, profits, idx + 1, capacity - wts[idx]),
					 backtrack(wts, profits, idx + 1, capacity)); // include wt[idx]
	} else {
		return backtrack(wts, profits, idx + 1, capacity);
	}
	
	// int profit2 = backtrack(wts, profits, idx + 1, capacity); // exclude wt[idx]
	// return max(profit1, profit2);
	
}

int recursiveDP(vector<int> &wts, vector<int> &profits, int idx, int capacity, vector<vector<int>> &dp) {
	
	if (idx >= wts.size() || capacity <= 0) {
		return 0;
	}
	
	if (dp[idx][capacity] != -1) {
		return dp[idx][capacity];
	}
	
	if (wts[idx] <= capacity) {
		dp[idx][capacity] = max(profits[idx] + recursiveDP(wts, profits, idx+1, capacity - wts[idx], dp),
				   recursiveDP(wts, profits, idx+1, capacity, dp));
	} else {
		dp[idx][capacity] = recursiveDP(wts, profits, idx+1, capacity, dp);
	}
	
	return dp[idx][capacity];
	
	
}


int knapsack(vector<int> &wts, vector<int> &profits, int capacity) {
	int n = wts.size();
	vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
	
	// return backtrack(wts, profits, 0, capacity);
	return recursiveDP(wts, profits, 0, capacity, dp);
}




int main() {
	// your code goes here
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};

	int capacity = 7;
	
	cout << "profit = " << knapsack(weights, profits, capacity) << endl;
	cout << "profit = " << knapsack(weights, profits, 6) << endl;
	return 0;
}
