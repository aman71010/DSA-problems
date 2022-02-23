#include<bits\stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        val = val;
        left = right = NULL;
    }
};

class Solution {
public:
    struct Info {
        int maxm;
        int minm;
        int sum;
        bool isBST;
    };
    
    Info solve(TreeNode* root, int &ans){
        if(!root){
            Info temp;
            temp.maxm = INT_MIN;
            temp.minm = INT_MAX;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }
        if(!root->left && !root->right){
            ans = max(ans, root->val);
            Info temp;
            temp.maxm = root->val;
            temp.minm = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            return temp;
        }
        Info l = solve(root->left, ans);
        Info r = solve(root->right, ans);
        Info retVar;
        if(l.isBST && r.isBST && l.maxm < root->val && r.minm > root->val){
            retVar.maxm = max(l.maxm, max(r.maxm, root->val));
            retVar.minm = min(l.minm, min(r.minm, root->val));
            retVar.sum = l.sum + r.sum + root->val;
            ans = max(ans, retVar.sum);
            retVar.isBST = true;
            return retVar;
        }
        retVar.isBST = false;
        return retVar;
    }
    int maxSumBST(TreeNode* root) {
        int ans = INT_MIN;
        Info res = solve(root, ans);
    	return ans<0 ? 0: ans;
    }
};