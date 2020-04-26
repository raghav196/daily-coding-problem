/**
 * Given a matrix of 1's and 0's and a source and a destination. 1 means free and 0 means wall.
 * Find if there exists a path from source to destination
 */

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isPath(vector<vector<int>> &grid, int x, int y, int destr, int destc) {
	
	int rows = grid.size();
	int cols = grid[0].size();
	if (grid[x][y] == 0) return false;
	
	// cout << "destr = " << destr << " " << "destc = " << destc << endl;
	// cout << "x = " << x << " " << "y = " << y << endl;
	
	if (x == destr && y == destc) {
		return true;
	}
	
	grid[x][y] = 0;
	bool a = false, b = false, c = false, d = false;
	if (x-1 >= 0 && grid[x-1][y] == 1) {
		a = isPath(grid, x-1, y, destr, destc);
	}
	
	if (x+1 < rows && grid[x+1][y] == 1) {
		b = isPath(grid, x+1, y, destr, destc);
	}
	
	if (y+1 < cols && grid[x][y+1] == 1) {
		c = isPath(grid, x, y+1, destr, destc);
	}
	
	if (y-1 >= 0 && grid[x][y-1] == 1) {
		d = isPath(grid, x, y-1, destr, destc);
	}
	
	return a || b || c || d;
}


bool isPathPossible(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dest) {
	int rows = grid.size();
	if (rows == 0) return false;
	
	int cols = grid[0].size();
	if (cols == 0) return false;
	
	return isPath(grid, src.first, src.second, dest.first, dest.second);
	
}

int main() {
	// your code goes here
	
	vector<vector<int>> grid = {
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 0, 1, 1}
	};
	
	cout << isPathPossible(grid, {0, 0}, {2, 0}) << endl;
	
	return 0;
}
