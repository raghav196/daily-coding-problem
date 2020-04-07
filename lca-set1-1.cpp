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

bool findPaths(Node *root, Node *node, vector<int> &arr) {
	if (root == NULL) return false;
	
	arr.push_back(root->val);
	if (root->val == node->val) {
		return true;
	}
	if (findPaths(root->left, node, arr) ||	findPaths(root->right, node, arr)) {
		return true;
	}
	arr.pop_back();
	return false;
	
}

void printPath(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
	cout << endl;
}

int lca(Node *root, Node *p, Node *q) {
	if (root == NULL) return INT_MAX;
	
	vector<int> path1;
	vector<int> path2;
	
	findPaths(root, p, path1);
	findPaths(root, q, path2);
	
	printPath(path1);
	printPath(path2);
	
	int i = 0, j = 0;
	while (i < path1.size() && j < path2.size()) {
		if (path1[i] == path2[j]) {
			i++;
			j++;
		} else {
			break;
		}
	}
	return path1[i-1];
}

int main() {
	// your code goes here
	Node *root = newNode(3);
	root->left = newNode(5);
	root->right = newNode(1);
	root->left->left = newNode(6);
	root->left->right = newNode(2);
	root->right->left = newNode(0);
	root->right->right = newNode(8);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	root->left->right->left->right = newNode(9);
	
	Node *p =  root->left->right->left; // 7
	Node *q = root->left->left; // 0
	
	cout << "lca = " << lca(root,p, q) << endl;
	
	
	return 0;
}
