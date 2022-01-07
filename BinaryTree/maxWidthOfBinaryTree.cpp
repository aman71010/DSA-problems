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
    // T->O(n) S->O(w)
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int first, last, currIdx, n = q.size();
            int minm = q.front().second;
            for(int i=1; i<=n; i++){
                TreeNode *curr = q.front().first;
                currIdx = q.front().second-minm;
                q.pop();
                if(i==1)
                    first = currIdx;
                if(i==n)
                    last = currIdx;
                if(curr->left)
                    q.push({curr->left, 2*currIdx+1});
                if(curr->right)
                    q.push({curr->right, 2*currIdx+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};