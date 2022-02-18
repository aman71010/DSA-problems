#include<bits\stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x){
    data = x;
    next = NULL;
    }
    
};

Node* reverseLinkedList(Node * head){
    if(!head && !head->next) return head;
    Node *curr = head, *prev = NULL, *temp;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev= curr;
        curr = temp;
    }
    return prev;
}

Node* solve(Node* head){
    if(!head && !head->next && !head->next->next) return head;
    Node* s = head;
    Node* f = head->next;
    while(f->next && f->next->next){
        s = s->next;
        f = f->next->next;
    }
    Node* mid = s->next;
    Node* secondHalf = s->next->next;
    s->next = NULL;
    Node* newHead = reverseLinkedList(head);
    Node* newSecHead = reverseLinkedList(secondHalf);
    Node* c = newHead;
    while(c->next){
        c = c->next;
    }
    c->next = mid;
    mid->next = newSecHead;
    return newHead;
}