/**
 * This problem was asked by Snapchat.
 * Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
 * For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, vector<int> brr) {
	
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	
	int n = arr.size();
	int i = 1, j = 0; // start with comparing 2nd arrival with 1st departure
	
	int classrooms = 1, ans = 1;
	
	while (i < n && j < n) {
		if (arr[i] <= brr[j]) {
			classrooms++;
			i++;
			
			if (classrooms > ans) ans = classrooms;
		} else {
			classrooms--;
			j++;
		}
	}
	
	return ans;
	
}




int main() {
	// your code goes here
	
	vector<int> arr = {30, 0, 60};
	vector<int> brr = {75, 50, 150};
	
	cout << "MIN CLASSROOMS = " << solve(arr, brr);
	return 0;
}
