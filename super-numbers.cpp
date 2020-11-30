/**
 * Generate all consecutive digit pairs differ by exactly 1 in the range of [1, N]
 */

#include <bits/stdc++.h>
using namespace std;


void dfs(int i, int n, vector<int>& result) {
	if (i < 1 || i >= n) return;
	
	result.push_back(i);
	
	int lastDigit = i % 10;
	int leftLastDigit = lastDigit - 1;
	int rightLastDigit = lastDigit + 1;
	
	if (leftLastDigit >= 0) {
		dfs(i*10 + leftLastDigit, n, result);
	}
	
	if (rightLastDigit < 10) {
		dfs(i*10 + rightLastDigit, n, result);
	}
	
	return;
}

vector<int> superNumbers(int n) {
	if (n == 0) return {};
	
	vector<int> result;
	for (int i = 1; i < 10; i++) {
		dfs(i, n, result);
	}
	return result;
}

int main() {
	// your code goes here
	
	vector<int> result = superNumbers(100);
	for (int ele: result) cout << ele << " ";
	cout << endl;
	
	return 0;
}
