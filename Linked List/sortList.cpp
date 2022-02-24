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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *s = head, *f = head->next;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode* secondList = s->next;
        s->next = NULL;
        ListNode *l = sortList(head);
        ListNode *r = sortList(secondList);
        return mergeTwoSortedList(l, r);
    }

    ListNode* mergeTwoSortedList(ListNode* l, ListNode* r){
        if(!l) return r;
        if(!r) return l;
        ListNode* curr = NULL;
        if(l->val < r->val){
            curr = l;
            curr->next = mergeTwoSortedList(l->next, r);
        } else {
            curr = r;
            curr->next = mergeTwoSortedList(l, r->next);
        }
        return curr;
    }
};