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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        while(curr){
            while(curr->next && curr->next->val == prev->next->val)
                curr = curr->next;
            if(prev->next==curr)
                prev = prev->next;
            else
                prev->next = curr->next;
            curr = curr->next;
        }
        head = dummy->next;
        delete(dummy);
        return head;
    }
};