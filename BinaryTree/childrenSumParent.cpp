#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if(!root || (!root->left && !root->right))
            return 1;
        int childSum = 0;
        if(root->left)
            childSum += root->left->data;
        if(root->right)
            childSum += root->right->data;
        return root->data==childSum && isSumProperty(root->left) && isSumProperty(root->right);
        
    }
};
