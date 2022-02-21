#include<bits\stdc++.h>
using namespace std;


//Definition for a binary tree TreeNode.
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
    // T-> o(n)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        distanceKUtil(root, target, k, res);
        return res;
    }

    int distanceKUtil(TreeNode* root, TreeNode* target, int k, vector<int> &res){
        if(!root) return -1;
        if(root==target){
            getTreeNodesAtKDisDown(root, k, res);
            return 0;
        }
        int dl = distanceKUtil(root->left, target, k, res);
        if(dl != -1){
            if(dl+1 == k)
                res.push_back(root->val);
            else
                getTreeNodesAtKDisDown(root->right, k-dl-2, res);
            return dl+1;
        }
        int dr = distanceKUtil(root->right, target, k, res);
        if(dr != -1){
            if(dr+1 == k)
                res.push_back(root->val);
            else
                getTreeNodesAtKDisDown(root->left, k-dr-2, res);
            return dr+1;
        }
        return -1;
    }

    void getTreeNodesAtKDisDown(TreeNode* root, int k, vector<int> &res){
        if(!root) return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        getTreeNodesAtKDisDown(root->left, k-1, res);
        getTreeNodesAtKDisDown(root->right, k-1, res);
    }

};