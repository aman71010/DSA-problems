#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// T-> O(n) 
class Solution{
    public: 
    void solve(Node* root, Node **prev, Node **head){
        if(!root) return;
        solve(root->left, &(*prev), &(*head));
        if(!(*head))
            *head = root;
        root->left = *prev;
        *prev = root;
        solve(root->right, &(*prev), &(*head));
        if(root->left)
            root->left->right = root;
    }

    Node* bToDLL(Node *root){
        if(!root) return root;
        Node *head, *prev;
        head = prev = NULL;
        solve(root, &prev, &head);
        return head;
    }
};


// T-> O(n) 
class Solution
{
    public: 
    void solve(Node* root, Node* &prev, Node* &head){
        if(!root) return;
        solve(root->left, prev, head);
        if(!head)
            head = root;
        root->left = prev;
        prev = root;
        solve(root->right, prev, head);
        if(root->left)
            root->left->right = root;
    }

    Node* bToDLL(Node *root){
        if(!root) return root;
        Node *head, *prev;
        head = prev = NULL;
        solve(root, prev, head);
        return head;
    }
};