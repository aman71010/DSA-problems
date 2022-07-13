#include<bits\stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


// T-> O(n*n*m), s-> (n) considering recurrsion stack
Node* flatten(Node *root){
    if(!root || !root->next)
        return root;
    Node *newHead = flatten(root->next);
    root->next = NULL;
    return mergeTwoLists(root, newHead);
}

Node* mergeTwoLists(Node* head1, Node* head2){  
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while(head1 && head2){
        if(head1->data <= head2->data){
            prev->bottom = head1;
            head1 = head1->bottom;
        } else {
            prev->bottom = head2;
            head2 = head2->bottom;
        }
        prev = prev->bottom;
    }
    if(head1)
        prev->bottom = head1;
    if(head2)
        prev->bottom = head2;
    head1 = dummy->bottom;
    delete(dummy);
    return head1;
}