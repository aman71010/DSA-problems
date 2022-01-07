#include<bits\stdc++.h>
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
    void allLeafPaths(TreeNode *root, vector<string> &res, string s){
        if(!root) return;
        s += to_string(root->val);
        if(root->left || root->right){
            s += "->";
        }
        if(!root->left && !root->right){
            res.push_back(s);
            return;
        }
        allLeafPaths(root->left, res, s);
        allLeafPaths(root->right, res, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s = "";
        allLeafPaths(root, res, s);
        return res;
    }
};