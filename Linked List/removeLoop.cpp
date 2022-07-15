#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int data;
    Node* next;
    Node(int _val) {
        data = _val;
        next = NULL;
    }
};


class Solution{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        Node *sp=head, *fp=head;
        while(sp && fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
            if(sp==fp) break;
        }
        if(!fp || !fp->next)
            return;
        if(sp == fp && sp == head){
            while(fp->next != sp)
                fp = fp->next;
            fp->next = NULL;
            return;
        }
        sp = head;
        while(fp->next != sp->next){
            fp = fp->next;
            sp = sp->next;
        }
        fp->next = NULL;
        return;
    }
};
