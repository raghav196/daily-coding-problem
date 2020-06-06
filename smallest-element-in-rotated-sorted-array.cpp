/**
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &arr) {
	int start = 0, end = arr.size();
	
	while (start <= end) {
		int mid = start + (end-start)/2;
		
		// mid is smallest element
		if (mid-1 >= 0 && arr[mid-1] > arr[mid]) {
			return arr[mid];
		}
		
		// mid+1 is smallest element
		if (mid+1 < arr.size() && arr[mid] > arr[mid+1]) {
			return arr[mid+1];
		}
		
		if (arr[start] < arr[mid]) {
			// first half is sorted i.e., from start to mid,
			// therefore, smallest element would be in second half
			start = mid+1;
		} else {
			// second half is sorted i.e., from mid to end,
			// therefore, smallest element would be present in other half
			end = mid - 1;
		}
	}
	
	return arr[0]; // array is not rotated
}


int main() {
	// your code goes here
	vector<int> arr = {5, 7, 10, 3, 4};
	cout << "min element = " << solve(arr) << endl;
	
	cout << "min element = " << solve(vector<int>{1, 2, 3, 4, 5, 6}) << endl;
	cout << "min element = " << solve(vector<int>{3, 4, 5, 6, 1, 2}) << endl;
	cout << "min element = " << solve(vector<int>{2, 3, 4, 5, 6, 1}) << endl;
	return 0;
}
