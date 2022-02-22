#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    // T-> O(N)
    int maxPathSum(Node* root){
        int ans = INT_MIN;
        int sum = maxPathSumUtil(root, ans);
        if(ans==INT_MIN)
            return sum;
        return ans;
    }

    int maxPathSumUtil(Node* root, int &ans){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        int ls = maxPathSumUtil(root->left, ans);
        int rs = maxPathSumUtil(root->right, ans);
        if(root->left && root->right){
            ans = max(ans, root->data+ls+rs);
            return max(ls, rs) + root->data;
        }
        if(root->left)
            return ls + root->data;
        else
            return rs + root->data;
    }
};