#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    // recursive approach T-> O(N) and S-> O(H)
    TreeNode* build(vector<int>& in, vector<int>& post, unordered_map<int, int> &mp, int &postIdx, int inStart, int inEnd) {
        if(inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = mp[root->val];
        root->right = build(in, post, mp, postIdx, inIdx+1, inEnd);
        root->left = build(in, post, mp, postIdx, inStart, inIdx-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        int last = n-1;
        return build(inorder, postorder, mp, last, 0, last);
    }
};