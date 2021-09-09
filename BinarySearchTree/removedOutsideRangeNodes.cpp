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
     Node* removekeys(Node* root, int l, int r) {
        if(!root) return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if(root->data < l){
            Node *rchild = root->right;
            delete root;
            return rchild;
        }
        else if(root->data > r){
            Node *lchild = root->left;
            delete root;
            return lchild;
        }
        return root;
    }
};