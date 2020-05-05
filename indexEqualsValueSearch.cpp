/**

Given a sorted array arr of distinct integers,
write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i.
Return -1 if there is no such index.

Examples:

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in array satisfies arr[i]
 */

#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(vector<int> &arr) {
	// your code goes here
  
	int start = 0, end = arr.size() - 1;
	int idx = -1;
  
	while (start <= end) {
    	int mid = start + (end - start)/2;
    	if (arr[mid] == mid) {
    		idx = mid;
    		end = mid - 1;
    	} else if (arr[mid] < mid) {
    		start = mid + 1;
    	} else {
    		end = mid - 1;
    	}
	}
	return idx;
}

int main() {
	
	vector<int> arr = {0, 1, 2, 3, 4, 5};
	cout << indexEqualsValueSearch(arr) << endl;
	
	arr = {-1,0,3,6};
	cout << indexEqualsValueSearch(arr) << endl;
	
	return 0;
}
