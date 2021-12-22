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
    // T-> o(n) S-> O(n)
    void reorderList(ListNode* head) {
        if(!head)
            return;
        vector<ListNode*> nodeMap;
        ListNode *curr = head;
        while(curr){
            nodeMap.push_back(curr);
            curr = curr->next;
        }
        int l=1, r=nodeMap.size()-1;
        for(int i=0; i<nodeMap.size(); i++, head=head->next){
            if(i&1)
                head->next = nodeMap[l++];
            else
               head->next = nodeMap[r--];
        }
        head->next = NULL;
    }
};