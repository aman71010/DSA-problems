#include <bits/stdc++.h>
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
    ListNode* sortedMerge(ListNode* head1, ListNode* head2){  
        if(!head1) return head2;
        if(!head2) return head1;
        if(head1->val <= head2->val){
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        } else {
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};


class Solution {
public:
    ListNode* sortedMerge(ListNode* head1, ListNode* head2){  
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while(head1 && head2){
        if(head1->val <= head2->val){
            prev->next = head1;
            head1 = head1->next;
        } else {
            prev->next = head2;
            head2 = head2->next;
        }
        prev = prev->next;
    }
    if(head1)
        prev->next = head1;
    if(head2)
        prev->next = head2;
    head1 = dummy->next;
    delete(dummy);
    return head1;
}  
};