#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	
	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
};

int dfs(Node* root) {
	if (root == NULL) return 0;
	
	if (root->left == NULL && root->right == NULL) return root->val;
	
	return root->val + max(dfs(root->left), dfs(root->right));
}

int getSum(Node* root) {
	return dfs(root);
}

void dfs(Node* root, int sum, vector<int> path, vector<vector<int>>& allPaths) {
    if (root == NULL) return;

    if (sum < 0) return;

    path.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
      allPaths.push_back(path);
      return;
    }

    dfs(root->left, sum-root->val, path, allPaths);
    dfs(root->right, sum-root->val, path, allPaths);

    path.pop_back();
    return;
  }


vector<vector<int>> findPaths(Node *root, int sum) {
    vector<vector<int>> allPaths;
    // TODO: Write your code here

    vector<int> pathSum;
    dfs(root, sum, pathSum, allPaths);  
    return allPaths;
  }

int main() {
	// your code goes here
	// Node* root = new Node(0);
	// root->left = new Node(21);
	// root->right = new Node(3);
	
	// root->left->left = new Node(4);
	// root->left->right = new Node(5);
	
	// root->right->left = new Node(6);
	// root->right->right = new Node(7);
	
	// root->right->left->right = new Node(-11);
	
	// cout << getSum(root) << endl;
	
	
	Node *root = new Node(12);
	root->left = new Node(7);
	root->right = new Node(1);
	root->left->left = new Node(4);
	root->right->left = new Node(10);
	root->right->right = new Node(5);
	
	vector<vector<int>> allPaths = findPaths(root, 23);
	
	for (vector<int> vec: allPaths) {
		for (int ele : vec) cout << ele << " ";
		cout << endl;
	}
	
	return 0;
}
