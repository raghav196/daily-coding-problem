/**
This problem was asked by Google.

Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
 */

#include <iostream>
using namespace std;

struct Node {
	int val;
	struct Node *next;
};

Node *newNode(int val) {
	Node *temp = new Node;
	temp->val = val;
	temp->next = NULL;
	return temp;
}

void reverse(Node *head) {
	
	if (head == NULL || head->next == NULL) return;
	
	swap(head->val, head->next->val);
	reverse(head->next->next);
	return;
}

Node *reverseInPairs(Node *head) {
	reverse(head);
	return head;
}

void printLL(Node *head) {
	Node *curr = head;
	while (curr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	// your code goes here
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	
	Node *ans = reverseInPairs(head);
	printLL(ans);
	
	return 0;
}
