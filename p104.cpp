/**
 * 
This problem was asked by Google.
Determine whether a doubly linked list is a palindrome. What if it’s singly linked?
For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.

 * 
 */


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node *next;
	struct Node *prev;
};

struct SingleLL {
	int val;
	struct SingleLL *next;
};

SingleLL *insertSLL(int val) {
	SingleLL *temp = new SingleLL;
	temp->val = val;
	temp->next = NULL;
	return temp;
}

Node *insertDLL(Node *head, int val) {
	Node *temp = new Node;
	temp->val = val;
	temp->next = NULL;
	temp->prev = NULL;
	if (head != NULL) {
		temp->next = head;
		head->prev = temp;
	}
	head = temp;
	return head;
}


void printDLL(Node *head) {
	Node *curr = head;
	while (curr != NULL) {
		cout << curr->val << "-->";
		curr = curr->next;
	}
	cout << "NULL\n";
}

void printSLL(SingleLL *head) {
	SingleLL *curr = head;
	while (curr != NULL) {
		cout << curr->val << "-->";
		curr = curr->next;
	}
	cout << "NULL\n";
}


bool isPalindromeDLL(Node *head) {
	if (head == NULL) return true;
	
	Node *start = head;
	Node *end = head;
	
	while (end->next != NULL) {
		end = end->next;
	}
	
	while (start != end) {
		if (start->val != end->val) return false;
		
		start = start->next;
		end = end->prev;
	}
	return true;
}

SingleLL *reverseSLL(SingleLL *head) {
	SingleLL *prev = NULL, *curr = head, *next = head;
	
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool isPalindromeSLL(SingleLL *head) {
	
	SingleLL *fast = head, *slow = head;
	
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	
	
	SingleLL *secondHalfHead = reverseSLL(slow);
	SingleLL *copySecondHalfHead = secondHalfHead;
	
	printSLL(head);
	printSLL(secondHalfHead);
	
	while (head != NULL && secondHalfHead != NULL) {
		if (head->val != secondHalfHead->val) return false;
		
		head = head->next;
		secondHalfHead = secondHalfHead->next;
	}
	
	return true;
}

int main() {
	// your code goes here
	
	Node *head = insertDLL(head, 1);
	head = insertDLL(head, 4);
	head = insertDLL(head, 3);
	head = insertDLL(head, 4);
	head = insertDLL(head, 1);

	
	// printDLL(head);
	// cout << "isPalindrome = " << isPalindromeDLL(head) << endl;
	
	
	
	SingleLL *start = insertSLL(1);
	start->next = insertSLL(4);
	start->next->next = insertSLL(3);
	start->next->next->next = insertSLL(4);
	start->next->next->next->next = insertSLL(11);
	
	printSLL(start);
	
	cout << isPalindromeSLL(start);
	
	return 0;
}
