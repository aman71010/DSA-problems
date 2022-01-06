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
    // T-> O(n) S-> O(n)
    void rv(TreeNode* root, int currL, int &maxL, vector<int> &res){
        if(!root) return;
        if(currL>maxL){
            res.push_back(root->val);
            maxL = currL;
        }
        rv(root->right, currL+1, maxL, res);
        rv(root->left, currL+1, maxL, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) {};
        vector<int> res;
        int maxL = 0;
        rv(root, 1, maxL, res);
        return res;
    }

    //-----------------------------------------------------------------------------------------
    // T-> O(n) S-> O(n)
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=1; i<=n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i==1){
                    res.push_back(curr->val);
                }
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
        return res;
    }
    
};