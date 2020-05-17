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

void solve(Node *root, int &sum) {
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        cout << "leaf = " << root->val << endl;
        sum += root->val;
        return;
    }
    
    solve(root->left, sum);
    solve(root->right, sum);
}

int sumLeaf(Node* root) {
    // Code here
    // int sum = 0;
    // solve(root, sum);
    // return sum;
    
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) return root->val;
    
    return sumLeaf(root->left) + sumLeaf(root->right);
}

int main() {
	// your code goes here
	Node *root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(60);
	root->right->left = newNode(90);
	// root->right->right = newNode(6);
	
	cout << "leaf sum = " << sumLeaf(root) << endl;
	return 0;
}
