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
    // T-> O(n) and S-> O(n)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *prev = NULL;
        int car = 0;
        while(l1 || l2){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }       
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += car;
            car = sum/10;
            ListNode *curr = new ListNode(sum%10);
            if(!head)
                head = curr;
            else
                prev->next = curr;
            prev = curr;
                
        }
        if(car)
            prev->next = new ListNode(car);
        return head;
    }
};