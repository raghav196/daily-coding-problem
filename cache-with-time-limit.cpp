/*
 * https://leetcode.com/problems/cache-with-time-limit
Write a class that allows getting and setting key-value pairs, however a time until expiration is associated with each key.

The class has three public methods:

set(key, value, duration): accepts an integer key, an integer value, and a duration in milliseconds. Once the duration has elapsed, the key should be inaccessible. The method should return true if the same un-expired key already exists and false otherwise. Both the value and duration should be overwritten if the key already exists.

get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.

count(): returns the count of un-expired keys.

 

Example 1:

Input: 
actions = ["TimeLimitedCache", "set", "get", "count", "get"]
values = [[], [1, 42, 100], [1], [], [1]]
timeDelays = [0, 0, 50, 50, 150]
Output: [null, false, 42, 1, -1]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 100ms. The value doesn't exist so false is returned.
At t=50, key=1 is requested and the value of 42 is returned.
At t=50, count() is called and there is one active key in the cache.
At t=100, key=1 expires.
At t=150, get(1) is called but -1 is returned because the cache is empty.
Example 2:

Input: 
actions = ["TimeLimitedCache", "set", "set", "get", "get", "get", "count"]
values = [[], [1, 42, 50], [1, 50, 100], [1], [1], [1], []]
timeDelays = [0, 0, 40, 50, 120, 200, 250]
Output: [null, false, true, 50, 50, -1, 0]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 50ms. The value doesn't exist so false is returned.
At t=40, a key-value pair (1: 50) is added with a time limit of 100ms. A non-expired value already existed so true is returned and the old value was overwritten.
At t=50, get(1) is called which returned 50.
At t=120, get(1) is called which returned 50.
At t=140, key=1 expires.
At t=200, get(1) is called but the cache is empty so -1 is returned.
At t=250, count() returns 0 because the cache is empty.
 

Constraints:

0 <= key, value <= 109
0 <= duration <= 1000
1 <= actions.length <= 100
actions.length === values.length
actions.length === timeDelays.length
0 <= timeDelays[i] <= 1450
actions[i] is one of "TimeLimitedCache", "set", "get" and "count"
First action is always "TimeLimitedCache" and must be executed immediately, with a 0-millisecond delay
 * 
 */


#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> cache;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

// will make all the operations O(logn) with priority queue especially the count() operation which was O(n) earlier
void cleanUp(int currentTime) {
	while(!minHeap.empty()) {
		pair<int, int> node = minHeap.top();
		if (node.first > currentTime) break; // minimum node has not expired
		minHeap.pop();
		
		if (cache.find(node.second) != cache.end() && cache[node.second].second <= currentTime) {
			cache.erase(node.second);
		}
	}
}


bool setKV(int key, int val, int currentTime, int duration) {
	cleanUp(currentTime);
	
	bool sameUnexpired = false;
	if (cache.find(key) != cache.end() && cache[key].second > currentTime) {
		sameUnexpired = true;
	}
	int expiryTime = currentTime + duration;
	cache[key] = {val, expiryTime};
	minHeap.push({expiryTime, key});
	
	return sameUnexpired;
}

int get(int key, int currentTime) {
	cleanUp(currentTime);
	if (cache.find(key) == cache.end()) return -1;
	return cache[key].first;
	// if (cache.find(key) == cache.end()) {
	// 	return -1;
	// } else {
	// 	if (cache[key].second <= currentTime) {
	// 		cache.erase(key);
	// 		return -1;
	// 	} else {
	// 		return cache[key].first;
	// 	}
	// }
}

int count(int currentTime) {
	cleanUp(currentTime);
	return cache.size();
	// int count = 0;
	// vector<int> keysToBeDeleted;
	// for (auto it = cache.begin(); it != cache.end(); it++) {
	// 	if (it->second.second <= currentTime) {
	// 		keysToBeDeleted.push_back(it->first);
	// 	} else {
	// 		count++;
	// 	}
	// }
	
	// for (int key: keysToBeDeleted) {
	// 	cache.erase(key);
	// }
	// return count;
}


int main() {
	// your code goes here
	cout <<"set(t=0) = " << setKV(1, 42, 0, 100) << endl;
	cout <<"get(t=50) = " << get(1, 50) << endl;
	cout <<"count(t=50) = " << count(50) << endl;
	cout <<"get(t=150) = " << get(1, 150) << endl;
	cout <<"count(t=150) = " << count(150) << endl;
	return 0;
}
