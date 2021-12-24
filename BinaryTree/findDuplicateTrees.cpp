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
    //t->O(n^2) s-> O(n^2)
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        inorder(root, m, res);
        return res;
    }

    string inorder(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &res){
        if(!root){
            return "";
        }
        string str = "(";
        str += inorder(root->left, m, res);
        str += to_string(root->val);
        str += inorder(root->right, m, res);
        str += ")";
        if(m[str]==1)
            res.push_back(root);
        m[str]++;
        return str;
    }
};