#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //---------------------------------------------------RECURSIVE--------------------------------------------------------------
    //exponntial t-> O(n^2)
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int dontRob = rob(root->left)+rob(root->right);
        int robRoot = root->val;
        if(root->left){
            robRoot += rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            robRoot += rob(root->right->left)+rob(root->right->right);
        }
        return max(dontRob, robRoot);
    }
    //---------------------------------------------------DP-----------------------------------------------------------------------  
    // t-> O(n) s-> O(n)
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(dp.count(root))
            return dp[root];
        int dontRob = rob(root->left)+rob(root->right);
        int robRoot = root->val;
        if(root->left){
            robRoot += rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            robRoot += rob(root->right->left)+rob(root->right->right);
        }
        return dp[root] = max(dontRob, robRoot);
    }
};