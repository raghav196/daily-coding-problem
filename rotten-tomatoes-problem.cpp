#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int minimumDays(int rows, int columns, vector<vector<int>> grid) {
	queue<pair<int, int>> q;
	for(int i = 0;i < grid.size();i++) {
		for(int j = 0;j < grid[i].size();j++) {
			if(grid[i][j] == 1) q.push({i, j});
		}
	}
 
	int ans = 0;
	while(!q.empty()) {
		int sz = q.size();
		ans++;
		for(int i = 0;i < sz;i++) {
			pair<int, int> t = q.front();
			q.pop();
			//cout << t.first << " " << t.second << endl;
			for(int _i = 0;_i < 4;_i++) {
				int newX = t.first + dx[_i];
				int newY = t.second + dy[_i];
				if(newX >= 0 && newX < rows && newY >= 0 && newY < columns && grid[newX][newY] == 0) {
					q.push({newX, newY});
					grid[newX][newY] = 1;
				}
			}
		}
	}
	return ans - 1;
}


int minDays (int rows, int columns, vector<vector<int>> grid) {
	
	queue<pair<int, int>> q;
	
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) q.push({i, j});
		}
	}
	
	int ans = 0;

	while (!q.empty()) {
		int sz = q.size();
		ans++;
		for (int i = 0; i < sz; i++) {
			pair<int,  int> temp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int newX = temp.first + dx[i];
				int newY = temp.second + dy[i];
			
				if (newX >= 0 && newX < rows && newY >= 0 && newY < columns && grid[newX][newY] == 0) {
					q.push({newX, newY});
					grid[newX][newY] = 1;
				}
			}
		}
	}
	
	return ans - 1;
	
}

int main() {
	// your code goes here
	vector<vector<int>> grid = {
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1}
	};
	
	vector<vector<int>> grid2 = {
		{1, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	
	// vector<vector<int>> grid3 = {{1}};
	
	cout << "ans = " << minDays(3, 3, grid2) << endl;
	cout << "ans2 = " << minimumDays(3, 3, grid2) << endl;
	
	return 0;
}
