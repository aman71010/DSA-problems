#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // T-> O(n) and S-> O(n)
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        vector<Node*> v;
        unordered_map<Node*, int> m;
        Node *curr = head, *newHead = NULL, *prev = NULL;
        int i=0;
        while(curr){
            Node *temp = new Node(curr->val);
            if(!newHead)
                newHead = temp;
            else
                prev->next = temp;
            prev = temp;
            v.push_back(temp);
            m[curr] = i++;
            curr = curr->next;
        }
        prev->next = NULL;
        Node *curr2 = newHead;
        curr = head;
        while(curr){
            if(!curr->random){
                curr2->random = NULL;
            }
            else{
                curr2->random = v[m[curr->random]];
            }
            curr = curr->next;
            curr2 = curr2->next;
        }
        return newHead;
    }
    //-------------------------------------------------------------------------------------------------
    // T-> O(n) and S-> O(n)
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node*, Node*> m;
        Node *curr = head, *newHead = NULL, *prev = NULL;
        while(curr){
            Node *temp = new Node(curr->val);
            m[curr] = curr->next;
            curr->next = temp;
            temp->random = curr;
            if(!newHead)
                newHead = temp;
            else
                prev->next = temp;
            prev = temp;
            curr = curr->next;
        }
        prev->next = NULL;
        curr = newHead;
        while(curr){
            if(!curr->random->random)
                curr->random = NULL;
            else
                curr->random = curr->random->random->next;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            curr->next = m[curr];
            curr = curr->next;
        }
        return newHead;
    }

    

};