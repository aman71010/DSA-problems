#include<bits\stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
    Node* reverseLinkedList(Node * head){
        if(!head || !head->next) return head;
        Node *curr = head, *prev = NULL, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }

    Node *compute(Node *head){
        if(!head || !head->next) return head;
        Node* newHead = reverseLinkedList(head);
        Node* curr = newHead;
        while(curr && curr->next){
            if(curr->data > curr->next->data){
                Node* next = curr->next->next;
                delete(curr->next);
                curr->next = next;
            }
            else
                curr = curr->next;
        }
        return reverseLinkedList(newHead);  
    }
    
};

// single traversal
class Solution{
    public:
    Node *compute(Node *head){
        if(!head || !head->next) return head;
        Node* nextNode = compute(head->next);
        if(head->data < nextNode->data){
            head->data = nextNode->data;
            Node* temp = nextNode->next;
            delete(nextNode);
            head->next = temp;
        }
        return head;  
    }
    
};