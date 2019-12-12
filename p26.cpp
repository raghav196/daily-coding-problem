/**
 * This problem was asked by Google.
 * Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.
 * The list is very long, so making more than one pass is prohibitively expensive.
 * Do this in constant space and in one pass.
 * 
 */ 

#include <iostream>
using namespace std;

struct Node { 
    int data; 
    struct Node *next; 
}; 
 
// Utility function creates a new binary tree node with given key 
Node *newNode(int k) { 
    Node *temp = new Node; 
    temp->data = k; 
    temp->next = NULL;
    return temp; 
} 


void deleteKthLastNode(Node *head, int k) {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL && k > 1) {
		return;
	}
	
	int count = 0;
	Node *temp = head;
	
	while (count < k) {
		temp = temp->next;
		count++;
	}
	
	cout << "aaa" << temp->data << endl;
	Node *prev = NULL;
	Node *temp2 = head;
	while (temp != NULL) {
		prev = temp2;
		temp2 = temp2->next;
		temp = temp->next;
	}
	
	Node *delNode = temp2;
	cout << "DELETED NODE = " << temp2->data << endl;
	prev->next = temp2->next;

}

void printLL(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << "-->";
		curr=curr->next;
	}
	cout << "NULL" << endl;
}


int main() {
	// your code goes here
	
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	
	printLL(head);
	deleteKthLastNode(head, 3);
	printLL(head);
	return 0;
}
