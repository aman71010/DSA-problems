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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr && curr->next){
            ListNode *a = curr->next, *b = curr->next->next;
            a->next = curr;
            curr->next = b;
            if(!prev)
                head = a;
            else
                prev->next = a;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }

    // recurrsion
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *remaining = head->next->next;
        ListNode *newHead = head->next;
        head->next->next = head;
        head->next = swapPairs(remaining);
        return newHead;
    }
};