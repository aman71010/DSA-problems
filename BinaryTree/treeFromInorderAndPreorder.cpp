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
    // T->O(n) S->O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;
        for(int i=0; i<inorder.size(); i++)
            um[inorder[i]] = i;
        int preIdx = 0;
        return build(preorder, inorder, um, 0, preorder.size()-1, preIdx);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &um, int inStart, int inEnd, int &preIdx){
        if(inStart>inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[preIdx]);
        int inIdx = um[preorder[preIdx]];
        preIdx++;
        node->left = build(preorder, inorder, um, inStart, inIdx-1, preIdx);
        node->right = build(preorder, inorder, um, inIdx+1, inEnd, preIdx);
        return node;
    }
};
