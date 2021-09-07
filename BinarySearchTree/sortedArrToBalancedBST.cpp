#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
};


class Solution 
{
    Node* newNode(int k){
        Node* temp = new Node;
        temp->data = k;
        temp->left = temp->right = NULL;
    }

    Node* constructBST(vector<int> &nums, int start, int end){
        if(start>end)
            return NULL;
        int mid = (start+end)/2;
        Node *root = newNode(mid);
        root->left = constructBST(nums, start, mid-1);
        root->right = constructBST(nums,  mid+1, end);
        return root;
    }

};