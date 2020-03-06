/**
 *
This problem was asked by Microsoft.

Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
  
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

vector<vector<int>> levelOrder(Node *root) {

	vector<vector<int>> ans;
	if (root == NULL) return ans;
	
	queue<Node *> q;
	q.push(root);
	
	
	while (!q.empty()) {
		int sz = q.size();
		vector<int> currentLevel;
		for (int i = 0; i < sz; i++) {
			Node *temp = q.front();
			q.pop();
			// cout << temp->val << " ";
			currentLevel.push_back(temp->val);
			
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		ans.push_back(currentLevel);
	}
	return ans;
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
	
	vector<vector<int>> ans = levelOrder(root);
	printPaths(ans);
	
	return 0;
}
