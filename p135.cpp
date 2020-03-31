/**
 * 
This question was asked by Apple.

Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node *left;
	struct Node *right;
};

Node *newNode(int val) {
	Node *temp = new Node;
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


void dfs(Node *root, int currentSum, int &minSum) {
	
	if (root == NULL) {
		return;
	}
	
	currentSum += root->val;
	// minSum = min(minSum, currentSum);
	cout << "currentSum = " << currentSum << endl;
	if (root->left == NULL && root->right == NULL) {
		minSum = min(minSum, currentSum);
		return;
	}
	
	dfs(root->left, currentSum, minSum);	
	dfs(root->right, currentSum, minSum);
	
	
	// arr.pop_back();
	// return;
}

void sumPath(Node *root, int target, vector<int> arr, vector<vector<int>> &ans) {
	
	if (root == NULL) {
		return;
	}
	
	arr.push_back(root->val);
	if (root->left == NULL && root->right == NULL && root->val == target) {
		ans.push_back(arr);
	}
	
	sumPath(root->left, target - root->val, arr, ans);
	sumPath(root->right, target - root->val, arr, ans);
	arr.pop_back();
	
}

vector<int> minimumSumPath(Node *root) {
	
	vector<int> arr;
	int minSum = numeric_limits<int>::max();
	if (root == NULL) return arr;
	
	vector<vector<int>> ans;
	dfs(root, 0, minSum);
	cout << "min sum = " << minSum << endl;
	
	sumPath(root, minSum, arr, ans);
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return arr;
	
}

int main() {
	// your code goes here
	Node *root = newNode(10);
	root->left = newNode(500);
	root->right = newNode(5);
	root->left->right = newNode(2);
	root->right->right = newNode(1);
	root->right->right->left = newNode(-1);
	
	vector<int> ans = minimumSumPath(root);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}
