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
    // t-> O(N) s-> O(H)
    int findTilt(TreeNode* root) {
        int ans = 0;
        findTiltRecur(root, ans);
        return ans;
    }

    int findTiltRecur(TreeNode* root, int &ans){
        if(!root)
            return 0;
        int left = findTiltRecur(root->left, ans);
        int right = findTiltRecur(root->right, ans);
        ans += abs(left-right);
        return left+right+root->val;
    }
    
};