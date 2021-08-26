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

    int height(Node* root){
        if(root==NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node *root)           //O(N^2)
    {
        if(root==NULL) return true;
        int diff = height(root->left) - height(root->right);
        if(diff<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        else return false;
    }

    int dfsHeight(Node* root){
        if(root==NULL) return 0;
        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) 
            return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) 
            return -1;
        if(abs(leftHeight-rightHeight)>1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node *root)           //O(N)
    {
        if(root==NULL) return true;
        if(dfsHeight(root) == -1)
            return false;
        else 
            return true;
    }
};

int main(){
    return 0;
}