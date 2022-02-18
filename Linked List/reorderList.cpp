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

void reorderList(Node* head) {
    if(!head || !head->next || !head->next->next) return;
    Node *s = head, *f = head->next;
    while(f && f->next){
        s = s->next;
        f = f->next->next;
    }
    Node *sHead = s->next;
    s->next = NULL;
    sHead = reverseLinkedList(sHead);
    Node *curr = head;
    while(curr->next){
        Node *temp1 = curr->next;
        Node *temp2 = sHead->next;
        curr->next = sHead;
        sHead->next = temp1;
        sHead = temp2;
        if(temp1) curr = temp1;
    }
    if(sHead)
        curr->next = sHead;
    return;
}