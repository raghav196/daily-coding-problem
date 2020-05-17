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

void solve(Node *root, vector<int> &arr) {
    if (root == NULL) return;
    
    if (root->left && !root->right) {
        arr.push_back(root->left->val);
        
    }
    
    if (!root->left && root->right) {
        arr.push_back(root->right->val);
        
    }
    
    solve(root->left, arr);
    solve(root->right, arr);
    return;
}


void printSibling(Node* node)
{
   // Your code here
   vector<int> arr;
   solve(node, arr);
   
   if (arr.size() == 0) cout << "-1";
   else {
       sort(arr.begin(), arr.end());
       for (int n: arr) {
           cout << n << " ";
       }
   }
}


int main() {
	// your code goes here
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->left->left = newNode(6);
	
	printSibling(root);
	return 0;
}
