/**
 * 
 * This problem was asked by Airbnb.
 * Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
 * For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
 * Follow-up: Can you do this in O(N) time and constant space?
 * 
 */

#include <iostream>
#include <vector>
using namespace std;


/**
 * Time complexity = O(n)
 * Space complexity = O(n) //extra array
 */
int solve(vector <int> arr) {
	
	int n = arr.size();
	if (n == 0) return 0;
	
	if (n == 1) return arr[0];
	
	if (n == 2) {
		return max(arr[0], arr[1]);
	}
	
	vector<int> dp(n, 0);
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
	}
	
	return dp[n-1];
}


/**
 * Time complexity = O(n)
 * Space complexity = O(1) // no extra array
 */
int solve2(vector <int> arr) {
	
	int n = arr.size();
	if (n == 0) return 0;
	
	if (n == 1) return arr[0];
	
	if (n == 2) {
		return max(arr[0], arr[1]);
	}
	
	int val1 = arr[0];
	int val2 = max(arr[0], arr[1]);
	
	int max_val;
	for (int i = 2; i < n; i++) {
		max_val = max(val2, val1 + arr[i]);
		val1 = val2;
		val2 = max_val;
	}
	
	return max_val;
}

int main() {
	// your code goes here
	
	vector<int> arr = {5, 1, 1, 5};
	cout << "MAX SUM = " << solve2(arr) << endl;
	return 0;
}
