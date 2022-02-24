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
    ListNode* mergeTwoLists(ListNode* l, ListNode* r) {
        if(!l) return r;
        if(!r) return l;
        ListNode* curr = NULL;
        if(l->val < r->val){
            curr = l;
            curr->next = mergeTwoLists(l->next, r);
        } else {
            curr = r;
            curr->next = mergeTwoLists(l, r->next);
        }
        return curr;
    }
};