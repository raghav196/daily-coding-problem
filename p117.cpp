/**
 *
This problem was asked by Facebook.
Given a binary tree, return the level of the tree with minimum sum.
 */
 
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
	int val;
	struct Node *left, *right;
};
 
Node *newNode(int val) {
	Node *temp = new Node;
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
 
void printPaths(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
}
 
pair<vector<int>, pair<int, int>> minSumLevel(Node *root) {
 
	vector<int> ans;
	if (root == NULL) return {ans, {-1, -1}};
 
	queue<Node *> q;
	q.push(root);
 
	int minSum = numeric_limits<int>::max();
	int level = 0, anslevel;
	while (!q.empty()) {
		level++;
		int sz = q.size();
		vector<int> currentLevel;
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			Node *temp = q.front();
			q.pop();
			
			sum += temp->val;
			currentLevel.push_back(temp->val);
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		if (sum < minSum) {
			minSum = sum;
			ans = currentLevel;
			anslevel = level; 
		}
	}
	return {ans, {minSum, anslevel}};
}
 
 
int main() {
	// your code goes here
	Node *root = newNode(-45);
	root->left = newNode(8);
	root->right = newNode(23);
 
	root->left->left = newNode(1);
	root->left->right = newNode(7);
	root->right->left = newNode(2);
	
	root->left->left->left = newNode(10);
	root->left->right->right = newNode(1);
 
	pair<vector<int>, pair<int, int>> p = minSumLevel(root);
	cout << "MIN SUM = " << p.second.first << endl;
	cout << "LEVEL = " << p.second.second << endl;
	cout << "LEVEL ELEMENTS\n";
	printPaths(p.first);
 
	return 0;
}
