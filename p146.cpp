/**
Good morning! Here's your coding interview problem for today.

This question was asked by BufferBox.

Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
should be pruned to:

   0
  / \
 1   0
    /
   1
We do not remove the tree at the root or its left child because it still has a 1 as a descendant.
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

void inorder(Node *root) {
	if (root == NULL) return;
	else {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

Node *removeZeroNodes(Node *root) {
	if (root == NULL) return NULL;
	
	root->left = removeZeroNodes(root->left);
	root->right = removeZeroNodes(root->right);
	
	if (root->left == NULL && root->right == NULL &&  root->val == 0) {
		root = NULL;
	}
	return root;
}


int main() {
	// your code goes here
	Node *root = newNode(0);
	root->left = newNode(1);
	root->right = newNode(0);
	root->right->left = newNode(1);
	root->right->right = newNode(0);
	root->right->left->left = newNode(0);
	root->right->left->right = newNode(0);
	
	inorder(root);
	cout << endl;
	
	Node *newRoot = removeZeroNodes(root);
	inorder(newRoot);
	cout << endl;
	return 0;
}
