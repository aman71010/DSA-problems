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
        unordered_map<Node*, Node*> m;
        Node *curr = head, *newHead = NULL, *prev = NULL;
        while(curr){
            Node *temp = new Node(curr->val);
            m[curr] = temp;
            if(!newHead)
                newHead = temp;
            else
                prev->next = temp;
            prev = temp;
            curr = curr->next;
        }
        prev->next = NULL;
        Node *curr2 = newHead;
        curr = head;
        while(curr){
            if(curr->random)
                curr2->random = m[curr->random];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return newHead;
    }
    //-------------------------------------------------------------------------------------------------
    // T-> O(n) and S-> O(1)
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *curr = head;
        while(curr){
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* copy = head->next;
        Node* res = head->next;
        while(curr && copy){
            curr->next = curr->next->next;
            curr = curr->next;
            if(curr)
                copy->next = curr->next;
            else
                break;
            copy = copy->next;
        }
        return res;
    }
};