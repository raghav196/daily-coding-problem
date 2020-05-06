/**
 * 0-1 Knapsack. Recusrive solution
 */


#include <bits/stdc++.h>
using namespace std;

int backtrack(vector<int> &wts, vector<int> &profits, int idx, int capacity) {
	
	if (capacity <= 0 || idx >= wts.size()) {
		return 0;
	}
	
	int profit1 = 0;
	if (wts[idx] <= capacity) {
		profit1 = profits[idx] + backtrack(wts, profits, idx + 1, capacity - wts[idx]); // include wt[idx]
	}
	
	int profit2 = backtrack(wts, profits, idx + 1, capacity); // exclude wt[idx]
	return max(profit1, profit2);
	
}


int knapsack(vector<int> &wts, vector<int> &profits, int capacity) {
	return backtrack(wts, profits, 0, capacity);
}




int main() {
	// your code goes here
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};

	int capacity = 7;
	
	cout << "profit = " << knapsack(weights, profits, capacity) << endl;
	return 0;
}
