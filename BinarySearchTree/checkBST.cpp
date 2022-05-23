#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
};


class Solution 
{
    public:
    //----------t-> O(N) aux space-> O(H)--------
    bool checkBst(Node *root, int min, int max){
        if(!root) return 1;
        if(root->data < min || root->data > max)
            return 0;
        return checkBst(root->left, min, root->data - 1) && checkBst(root->right, root->data + 1, max);
    }

    bool isBST(Node* root) 
    {
        return checkBst(root, INT_MIN, INT_MAX);
    }

};

class Solution {
    public:
    //----------t-> O(N) aux space-> O(H)--------
    bool checkBst(Node *root, Node* &prev){
        if(root){
            if(!checkBst(root->left, prev))
                return false;
            if(prev && root->data <= prev->data)
                return false;
            prev = root;
            return checkBst(root->right, prev);
        }
        return true;
    }

    bool isBST(Node* root) {
        Node* prev = NULL;
        return checkBst(root, prev);
    }

};