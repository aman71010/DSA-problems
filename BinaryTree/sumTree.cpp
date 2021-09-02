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


    //-----------------  T -> O(n*n)  ----------------------------
    int getSum(Node *root){
        if(!root)
            return 0;
        return getSum(root->left) + root->data + getSum(root->right);
    }

    bool isSumTree(Node* root)
    {
        int ls, rs;
        if(!root || (!root->left && !root->right))
            return 1;
        ls = getSum(root->left);
        rs = getSum(root->right);
        if(root->data==ls+rs && isSumTree(root->left) && isSumTree(root->right))
            return 1;
        return 0;
    }

    //---------------------- O(n) -----------------------

    bool isLeafNode(Node* root){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        return 0;
    }

    bool isSumTree(Node* root)
    {
        int ls, rs;
        if(!root || isLeafNode(root)) return 1;
        
        if(isSumTree(root->left) && isSumTree(root->right)){
            if(!root->left)
                ls = 0;
            else if(isLeafNode(root->left))
                ls = root->left->data;
            else
                ls = 2*root->left->data;
            if(!root->right)
                rs = 0;
            else if(isLeafNode(root->right))
                rs = root->right->data;
            else
                rs = 2*root->right->data;
            return (root->data==ls+rs);
        }
        return 0;
    }
};