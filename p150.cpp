/**
This problem was asked by LinkedIn.

Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].

 */

#include <bits/stdc++.h>
using namespace std;

int distFromCP(pair<int, int> p, pair<int, int> cp) {
	int x = cp.first - p.first;
	int y = cp.second - p.second;
	return x*x + y*y;
}

// struct cmp {
// 	bool operator()(pair<int, int> a, pair<int, int> b) const {
		
// 	}
// };

vector<pair<int, int>> getKNearestPoints(vector<pair<int, int>> points, pair<int, int> cp, int k) {
	
	vector<pair<int, int>> maxHeap;
	
	for (int i = 0; i < k; i++) {
		maxHeap.push_back(points[i]);
	}
	
	make_heap(maxHeap.begin(), maxHeap.end());
	
	pair<int, int> front = maxHeap.front();
	// cout << front.first << " " << front.second << endl;
	for (int i = k; i < points.size(); i++) {
		pair<int, int> front = maxHeap.front();
		if (distFromCP(points[i], cp) < distFromCP(front, cp)) {
			pop_heap(maxHeap.begin(), maxHeap.end());
			maxHeap.pop_back();
			
			maxHeap.push_back(points[i]);
			push_heap(maxHeap.begin(), maxHeap.end());
		}
	}
	return maxHeap;
	
}


int main() {
	// your code goes here
	
	vector<pair<int, int>> points = {{0, 0}, {5, 4}, {3, 1}, {1, 2}};
	pair<int, int> cp = {1, 2};
	int k = 2;
	
	vector<pair<int, int>> ans;
	ans = getKNearestPoints(points, cp, k);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ", " << ans[i].second << endl;
	}
	return 0;
}
