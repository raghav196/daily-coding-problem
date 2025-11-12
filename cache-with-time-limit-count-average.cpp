/**
 * Cache with time limit. https://leetcode.com/problems/cache-with-time-limit
 * Additional Methods
 * count(int currentTime) - returns the no of unexpired keys at time = currentTime
 * getAverage(int currentTime) - returns the average of unexpired key values at time = currentTime
 */

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> cache;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
long long totalSum = 0;
int liveCount = 0;

void cleanUp(int currentTime) {
	while(!minHeap.empty()) {
		pair<int, int> node = minHeap.top();
		int key = node.second;
		int timestamp = node.first;
		if (timestamp > currentTime) break; // minimum node has not expired
		minHeap.pop();
		
		if (cache.find(key) != cache.end() && cache[key].second <= currentTime) {
			totalSum -= cache[key].first; // remove the value from the total sum of the expired key
			liveCount--;
			cache.erase(key);
		}
	}
}


bool setKV(int key, int val, int currentTime, int duration) {
	cleanUp(currentTime);
	
	bool sameUnexpired = false;
	if (cache.find(key) != cache.end() && cache[key].second > currentTime) {
		sameUnexpired = true;
		totalSum -= cache[key].first; // remove the old value of the key. the new is added below
	} else {
		// key is either not present or is expired.
		// if expired, it would have been removed in the cleanup
		liveCount++;
	}
	int expiryTime = currentTime + duration;
	cache[key] = {val, expiryTime};
	minHeap.push({expiryTime, key});
	
	totalSum += val;
	
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
	return liveCount;
	// return cache.size();
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

double getAverage(int currentTime) {
	cleanUp(currentTime);
	cout << totalSum << " " << liveCount << endl;
	if (liveCount == 0) return 0.0;
	return (double)(totalSum/(double)liveCount);
}


int main() {
	// your code goes here
	cout <<"set(t=0) = " << setKV(1, 42, 0, 100) << endl;
	cout <<"get(t=50) = " << get(1, 50) << endl;
	cout <<"count(t=50) = " << count(50) << endl;
	cout <<"set(t=50) = " << setKV(2, 4, 50, 100) << endl;
	cout <<"set(t=55) = " << setKV(2, 10, 50, 100) << endl;
	cout <<"getAverage(t=60) = " << getAverage(60) << endl;
	cout <<"get(t=150) = " << get(1, 150) << endl;
	cout <<"count(t=150) = " << count(150) << endl;
	cout <<"getAverage(t=150) = " << getAverage(150) << endl;
	return 0;
}
