/**
 * This problem was asked by Facebook.
   Given a binary tree, return all paths from the root to leaves.

   For example, given the tree:

   1
  / \
 2   3
    / \
   4   5
   
   Return [[1, 2], [1, 3, 4], [1, 3, 5]].
 * 
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

void printPaths(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printArray(vector<int> arr) {
	cout << "PRINT ARRAY\n";
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl;
}

void rootToLeafPaths(Node *root, vector<int> arr, vector<vector<int>> &ans) {
	if (root == NULL) {
		return;
	}
	
	if (root->left == NULL && root->right == NULL) {
		// cout << root->val << endl;
		arr.push_back(root->val);
		ans.push_back(arr);
	}
	// cout << "aa " << root->val << endl;
	arr.push_back(root->val);
	// printArray(arr);
	rootToLeafPaths(root->left, arr, ans);
	rootToLeafPaths(root->right, arr, ans);
	// arr.pop_back();
	// printArray(arr);
	
}


int main() {
	// your code goes here
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(44);
	root->left->right = newNode(45);
	
	root->left->right->right = newNode(55);
	
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	
	vector<vector<int>> ans;
	vector<int> arr;
	
	rootToLeafPaths(root, arr, ans);
	printPaths(ans);
	
	return 0;
}
