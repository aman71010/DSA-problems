#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(!root || (!root->left && !root->right))
            return;
        mirror(root->left);
        mirror(root->right);
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *c = q.front();
            q.pop();
            Node* temp = c->left;
            c->left = c->right;
            c->right = temp;
            if(c->left)
                q.push(root->left);
            if(c->right)
                q.push(root->right);
        }
    }
};
