/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 */


#include <bits/stdc++.h>
using namespace std;

int backtrack(vector<vector<int>>& arr, vector<vector<int>> &dp, int x, int y, int dx, int dy) {
    int rows = arr.size();
    int cols = arr[0].size();
        
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        return 0;
    }
        
    if (arr[x][y] == 1) return 0;
    
    if (x == dx && y == dy) {
        return 1;
    }
        
    if (dp[x][y] != -1) {
    	return dp[x][y];
    }
    // int up = 0;
    // int left = 0;
    // dp[x][y] = 0;
    
    dp[x][y] = backtrack(arr, dp, x-1, y, dx, dy) +  backtrack(arr, dp, x, y-1, dx, dy);
    
        
    // return up + left;
    return dp[x][y];
	
}
    
    
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

  int rows = obstacleGrid.size();
  int cols = obstacleGrid[0].size();
  
  vector<vector<int>> dp(rows, vector<int>(cols, -1));
  return backtrack(obstacleGrid, dp, rows - 1, cols - 1, 0, 0);

}

int main() {
	// your code goes here
	
	vector<vector<int>> grid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	
	cout << uniquePathsWithObstacles(grid) << endl;
	return 0;
}
