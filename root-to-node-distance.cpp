/**
 * Given root of a binary tree and a key x in it, find distance of the given key from root.
 * Distance means number of edges between two nodes.
 */

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

int nodeDistanceFromRoot(Node *root, Node *target, int dist) {
	
	if (root == NULL) {
		return -1;
	}
	if (root == target) {
		cout << "RETURNED DIST = " << dist << endl;
		return dist;
	}
	
	cout << "root->val = " << root->val << endl;
	int x = nodeDistanceFromRoot(root->left, target, dist + 1);
	int y = nodeDistanceFromRoot(root->right, target, dist + 1);
	
	cout << "(x, y) = " << x << " " << y  << endl;
	if (x == -1 && y == -1) return -1;
	if (x != -1 && y == -1) return x;
	if (x == -1 && y != -1) return y;
}

int main() {
	// your code goes here
	
	Node *root = newNode(5);
	
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->left->right = newNode(25);
	root->right->left = newNode(30);
	root->right->right = newNode(35);
	root->left->right->right = newNode(45);
	
	Node *target = root->left->right->right;
	int distance = nodeDistanceFromRoot(root, target, 0);
	
	cout << "DISTANCE = " << distance << endl;
	

	cout << endl;
	return 0;
}
