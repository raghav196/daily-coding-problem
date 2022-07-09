#include <bits/stdc++.h>
using namespace std;

int ceilingNumber(vector<int> arr, int target) {
	int n = arr.size();
	if (n == 0) return -1;
	
	if (arr[0] >= target) return 0;
	if (arr[n-1] < target) return -1;
	
	int start = 0, end = n-1;
	int idx = -1;
	while (start <= end) {
		int mid = start + (end-start)/2;
		
		if (arr[mid] == target) {
			return mid;
		}
		
		if (arr[mid] < target) {
			start = mid+1;
		} else {
			idx = mid;
			end = mid-1;
		}
	}
	
	// return idx;
	return start;
}

int floorNumber(vector<int> arr, int target) {
	int n = arr.size();
	if (n == 0) return -1;
	
	if (arr[0] > target) return -1;
	if (arr[n-1] <= target) return n-1;
	
	int start = 0, end = n-1;
	int idx = -1;
	while (start <= end) {
		int mid = start + (end-start)/2;
		
		if (arr[mid] == target) {
			return mid;
		}
		
		// floor is either mid or lies [mid+1, end]
		if (arr[mid] < target) {
			idx = mid;
			start = mid+1;
		} else { // target < arr[mid], floor will lie in [start, mid-1];
			end = mid-1;
		}
	}
	
	// return idx;
	return end;
}


int main() {
	// your code goes here
	
	cout << ceilingNumber({1,7,8,10,13,15}, 12) << endl;
	cout << ceilingNumber({1,7,8,10,13,15}, 2) << endl;
	cout << ceilingNumber({1,7,8,10,13,15}, 0) << endl;
	cout << ceilingNumber({1,5}, 4) << endl;
	cout << ceilingNumber({1}, 0) << endl;
	cout << ceilingNumber({1,2,3,4,5}, 3) << endl;
	cout << ceilingNumber({1,7,8,10,13,15}, 14) << endl;
	cout << ceilingNumber({1,7,8,10,13,15}, 14) << endl;
	
	cout << "--------------------------------------------\n";
	
	cout << floorNumber({1,7,8,10,13,15}, 12) << endl;
	cout << floorNumber({1,7,8,10,13,15}, 2) << endl;
	cout << floorNumber({1,7,8,10,13,15}, 0) << endl;
	cout << floorNumber({1,5}, 4) << endl;
	cout << floorNumber({1}, 0) << endl;
	cout << floorNumber({1,2,3,4,5}, 3) << endl;
	cout << floorNumber({1,7,8,10,13,15}, 14) << endl;
	cout << floorNumber({1,7,8,10,13,15}, 17) << endl;
	
	
	return 0;
}
