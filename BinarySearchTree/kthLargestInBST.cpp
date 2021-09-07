#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution 
{
    public:

    // --------------recursive approach t-> O(H+k) and s->O(H)---------------------
    void reverseInorder(Node *root, int k, int &res, int &count){
        if(!root || count>=k) return;
        reverseInorder(root->right, k, res, count);
        count++;
        if(k==count){
            res = root->data;
            return;
        }   
        reverseInorder(root->left, k, res, count);
    }

    int kthLargest(Node *root, int k){
        int res = -1; 
        int count = 0;
        reverseInorder(root, k, res, count);
        return res;
    }

    
};