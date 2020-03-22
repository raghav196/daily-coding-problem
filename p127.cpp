#include <bits/stdc++.h>
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

void printLL(Node *head) {
	Node *curr = head;
	while (curr) {
		cout << curr->val << "-->";
		curr = curr->next;
	}
	cout << "NULL\n";
}

Node *add2LL(Node *head1, Node *head2) {
	
	if (head1 == NULL && head2 == NULL) return head1;
	if (head1 != NULL && head2 == NULL) return head1;
	if (head1 == NULL && head2 != NULL) return head2;
	
	Node *curr1 = head1;
	Node *curr2 = head2;
	
	int carry = 0;
	Node *temp = newNode(-1);
	Node *newHead = temp;
	while (curr1 != NULL && curr2 != NULL) {
		int sum = carry + curr1->val + curr2->val;
		carry = sum / 10;
		temp->next = newNode(sum % 10);
		temp = temp->next;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	// printLL(newHead);
	while (curr1 != NULL) {
		int sum = carry + curr1->val;
		carry = sum / 10;
		temp->next = newNode(sum % 10);
		temp = temp->next;
		curr1 = curr1->next;
	}
	
	while (curr2 != NULL) {
		int sum = carry + curr2->val;
		carry = sum / 10;
		temp->next = newNode(sum % 10);
		temp = temp->next;
		curr2 = curr2->next;
	}
	
	if (carry > 0) {
		temp->next = newNode(carry);
	}
	return newHead->next;

}

int main() {
	// your code goes here
	
	Node *head1 = newNode(9);
	// cout << head1->val << head1->next;
	head1->next = newNode(9);
	// cout << head1->next->val;
	head1->next->next = newNode(9);
	head1->next->next->next = newNode(9);
	
	Node *head2 = newNode(9);
	head2->next = newNode(9);
	
	printLL(head1);
	printLL(head2);
	
	Node *ans = add2LL(head1, head2);
	printLL(ans);
	
	
	return 0;
}
