#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> mat) {
	int n = mat.size();
	int m = mat[0].size();
	
	int i = 0, j = m-1;
    int ans = 0;
    
    while (i < n && j >= 0) {
        if (mat[i][j] == 1) {
            j--;
            ans = i;
        } else {
            i++;
        }
    }
    return ans;
}

int main() {
	// your code goes here
	vector<vector<int>> mat = {{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
	cout << solve(mat) << endl;
	
	mat = {{0,0},{1,1}};
	cout << solve(mat) << endl;
	
	mat = {{0,1,1,1},{0,1,1,1},{0,1,1,1},{1,1,1,1}};
	cout << solve(mat) << endl;
	return 0;
}
