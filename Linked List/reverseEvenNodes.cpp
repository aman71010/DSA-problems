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

class Solution
{
    public:
    void rearrange(struct Node *head){
        if(!head || !head->next || !head->next->next) return;
        Node *exHead = NULL, *exCurr = NULL;
        Node *curr = head;
        while(curr->next || curr->next->next){
            if(curr->next){
                if(!exHead)
                exHead = curr->next;
                else
                    exCurr->next = curr->next;
                exCurr = curr->next;
            }
            if(curr->next->next){
                curr->next = curr->next->next;
                curr = curr->next;
            }
            
        }
        exCurr->next = NULL;
        curr->next = reverseLinkedList(exHead);
        return;
    }

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
};

class Solution
{
    public:
    void rearrange(struct Node *head){
        if(!head || !head->next || !head->next->next) return;
        Node *even = head->next;
        head->next = head->next->next;
        head = head->next;
        even->next = NULL;
        while(head->next){
            Node *temp = head->next->next;
            head->next->next = even;
            even = head->next;
            head->next = temp;
            if(temp)
                head = temp;
        }
        head->next = even;
        return;
    }
};