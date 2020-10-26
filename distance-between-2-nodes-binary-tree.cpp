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

void inorder(Node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
	return;
}

Node* getLCA(Node* root, Node* n1, Node* n2) {
	if (root == NULL) return NULL;
	
	if (root == n1 || root == n2) return root;
	
	Node* left = getLCA(root->left, n1, n2);
	Node* right = getLCA(root->right, n1, n2);
	
	if (left && right) return root;
	
	if (left == NULL) return right;
	else return left;
}

int getDistance(Node* root, Node* n1, int level) {
	if (root == NULL) return -1;
	
	if (root == n1) return level;
	
	int left = getDistance(root->left, n1, level+1);
	if (left != -1) return left;
	
	int right = getDistance(root->right, n1, level+1);
	return right;
}

int distBetween2Nodes(Node* root, Node *n1, Node* n2) {
	if (root == NULL) return -1;
	
	int dn1 = getDistance(root, n1, 0);
	int dn2 = getDistance(root, n2, 0);
	
	if (dn1 == -1 || dn2 == -1) return -1;
	
	Node* lca = getLCA(root, n1, n2);
	int dlca = getDistance(root, lca, 0);
	
	return (dn1-dlca) + (dn2-dlca);
}


int main() {
	// your code goes here
	
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	root->right->left->right = new Node(8);
	
	// inorder(root);
	Node* n1 = root->right;
	Node* n2 = root->right->left->right;
	
	int distance = distBetween2Nodes(root, n1, n2);
	cout << "distance = " << distance << endl; 
	// Node* lca = getLCA(root, n1, n2);
	// if (lca) cout << "lca = " << lca->val << endl;
	
	return 0;
}
