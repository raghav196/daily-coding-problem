#include <iostream>
#include <vector>
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

void getNodesAtKDistanceFromRoot(Node *root, int k, vector<int> &ans) {
	
	if (root == NULL) {
		return;
	}
	if (k == 0 && root != NULL) {
		ans.push_back(root->val);
		return;
	}
	
	getNodesAtKDistanceFromRoot(root->left, k-1, ans);
	getNodesAtKDistanceFromRoot(root->right, k-1, ans);
	
}

int main() {
	// your code goes here
	
	Node *root = newNode(1);
	
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(8);
	
	int k = 0;
	vector<int> ans;
	getNodesAtKDistanceFromRoot(root, k, ans);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
