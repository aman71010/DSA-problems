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

class Solution{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(!head || !head->next) return head;
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node *prev0 = dummy0, *prev1 = dummy1, *prev2 = dummy2;
        while(head){
            if(head->data == 0){
                prev0->next = head;
                prev0 = head;
            } else if(head->data == 1){
                prev1->next = head;
                prev1 = head;
            } else{
                prev2->next = head;
                prev2 = head;
            }
            head = head->next;
        }
        
        if(dummy0->next){
            head = dummy0->next;
            prev0->next = NULL;
        } 
        if(dummy1->next){
            if(dummy0->next){
                prev0->next = dummy1->next;
            } else {
                head = dummy1->next;
            }
            prev1->next = NULL;
        }
        if(dummy2->next){
            if(dummy1->next){
                prev1->next = dummy2->next;
            } else if(dummy0->next){
                prev0->next = dummy2->next;
            } else {
                head = dummy2->next;
            }
            prev2->next = NULL;
        }
        delete(dummy0);
        delete(dummy1);
        delete(dummy2);
        return head;
    }
};