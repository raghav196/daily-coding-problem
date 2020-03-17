/**
This question was asked by Zillow.

You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.

 * 
 */

#include <bits/stdc++.h>
using namespace std;

// int maxCost = 0;

int solve(vector<vector<int>> arr, int r, int c, int i, int j) {
	
	if (i == r-1 && j == c-1) {
		return 0;
	}
	
	if (i == r-1 && j != c-1) {
		return arr[i][j] + solve(arr, r, c, i, j+1);
	}
	
	if (i != r-1 && j == c-1) {
		return  arr[i][j] + solve(arr, r, c, i+1, j);
	}
	
	// int cost = arr[i][j];
	// int cost = arr[i][j] + maxCost;
	// int x = arr[i][j] + solve(arr, r, c, i+1, j);
	// int y = arr[i][j] + solve(arr, r, c, i, j+1);
	
	// int maxCostt = max(x, y);
	// return maxCostt;
	
	return arr[i][j] + max(solve(arr, r, c, i+1, j), solve(arr, r, c, i, j+1));
	
	
}


int main() {
	// your code goes here
	vector<vector<int>> arr = {
		{0, 3, 1, 1},
		{2, 0, 4, 4},
		{1, 5, 3, 1}
	};
	
	int maxCost = 0;
	int cost = solve(arr, 3, 4, 0, 0);
	cout << "COST = " << cost << endl;
	return 0;
}
