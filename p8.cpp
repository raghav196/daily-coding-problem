/**
 * This problem was asked by Google.
 * A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
 * Given the root to a binary tree, count the number of unival subtrees.
 * For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1 
 
 */
 
#include <iostream>
using namespace std;
 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
 
// Utility function creates a new binary tree node with given key 
Node *newNode(int k) { 
    Node *temp = new Node; 
    temp->data = k; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
} 
 

bool isUnival(Node *root) {
	if (root == NULL) {
		return true;
	}
	
	// not unival as left node value is different than root value
	if (root->left != NULL && root->left->data != root->data) {
		return false;
	}
	// not unival as right node value is different than root value
	if (root->right != NULL && root->right->data != root->data) {
		return false;
	}
	
	return isUnival(root->left) && isUnival(root->right);
}

int countUnivalSubtrees(Node *root) {
	if (root == NULL) {
		return 0;
	}
	
	int count = countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
	
	if (isUnival(root)) {
		count += 1;
	}
	return count;
}


 
int main() {
    // your code goes here
 
    Node *root = newNode(1);
    root->left = newNode(1);
    root->right = newNode(1);
 
    root->right->left = newNode(1);
    root->right->right = newNode(1);
 
    // root->right->left->left = newNode(1);
    // root->right->left->right = newNode(1);
    root->right->right->right = newNode(2);
 
    cout << "UNIVAL SUBTREES COUNT = " << countUnivalSubtrees(root);
 
    return 0;
}
