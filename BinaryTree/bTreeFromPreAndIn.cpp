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

    Node* constructTree(int in[], int inStart, int inEnd, int pre[], int preStart, int preEnd, unordered_map<int, int> um){
        if(inStart>inEnd || preStart>preEnd)
            return NULL;
        Node *root;
        root->data = pre[preStart];
        int inRoot = um[root->data];
        int numsLeft = inRoot-inStart;
        root->left = constructTree(in, inStart, inRoot-1, pre, preStart+1, preStart+numsLeft, um);
        root->right = constructTree(in, inRoot+1, inEnd, pre, preStart+numsLeft+1, preEnd, um);
        return root;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int, int> um;
        for(int i=0; i<n; i++)
            um[in[i]] = i;
        Node* root = constructTree(in, 0, n-1, pre, 0, n-1, um);
        return root;

    }
};