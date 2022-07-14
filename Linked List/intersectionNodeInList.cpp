#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // T-> O(n+m) and S-> O(1)
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(!head1 || !head2)
            return NULL;
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
            if(p1==p2){
                if(p1) return p1;
                return NULL;
            }
            if(!p1) p1 = head2;
            if(!p2) p2 = head1;
        }
        if(p1) return p1;
        return NULL;
    }
};
