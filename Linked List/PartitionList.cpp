#include<bits\stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *fHead = NULL, *sHead = NULL;
        ListNode *fCurr = NULL, *sCurr = NULL;
        while(head){
            if(head->val<x){
                if(!fHead)
                    fHead = head;
                else
                    fCurr->next = head;
                fCurr = head;
            } else {
                if(!sHead)
                    sHead = head;
                else
                    sCurr->next = head;
                sCurr = head;
            }
            head = head->next;
        }
        if(fHead && sHead){
            fCurr->next = sHead;
            sCurr->next = NULL;
            return fHead;
        }
        return fHead ? fHead: sHead;
    }
};