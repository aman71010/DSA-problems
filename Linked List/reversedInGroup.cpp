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
    // T-> O(n) and S-> O(n\k)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        ListNode *curr = head;
        int n = 0;
        while(curr){
            n++;
            curr = curr->next;
        }
        int grp = n/k;
        return reverse(head, k, grp-1);
    }

    ListNode* reverse(ListNode* head, int k, int grp) {
        if(!head)
            return NULL;
        ListNode *next = NULL, *prev = NULL, *curr = head;
        int j = 0;
        while(curr && j<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            j++;
        }
        if(next && grp--)
            head->next = reverse(next, k, grp);
        else
            head->next = next;
        return prev;
    }
    //-----------------------------------------------------------------------------------------------------
    // T-> O(n) and S-> O(k)const
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        stack<ListNode*> st;
        int n = getLen(head);
        int grp = n/k;
        ListNode *curr = head, *prev = NULL;
        while(curr && grp){
            int j = 1;
            while(curr && j<=k){
                st.push(curr);
                curr = curr->next;
                j++;
            }
            while(st.empty()){
                if(!prev){
                    head = st.top();
                    st.pop();
                    prev = head;
                }
                else{
                    prev->next = st.top();
                    st.pop();
                    prev = prev->next;
                }
            }
            grp--;
        }
        prev->next = curr;
        return head;
    }

    int getLen(ListNode *head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
};