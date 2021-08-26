#include<bits\stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution 
{
    public:
    int ans = 0;
    int height(Node* root) {
        if(root==NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        ans = max(leftHeight+rightHeight+1, ans);
        return max(leftHeight, rightHeight) + 1;
    }
    
    int diameter(Node* root){
        height(root);
        return ans;
    }
};