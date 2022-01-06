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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        unordered_map<int, vector<pair<int,int>>> m;
        queue<pair<TreeNode*,int>> q;
        int minHD = 0, maxHD = 0;
        int depth = 0;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* c = q.front().first;
                int hd = q.front().second;
                q.pop();
                m[hd].push_back({depth,c->val});
                if(c->left)
                    q.push({c->left, hd-1});
                if(c->right)
                    q.push({c->right, hd+1});
                minHD = min(minHD, hd);
                maxHD = max(maxHD, hd);
            }
            depth++;
        }
        for(int j=minHD; j<=maxHD; j++){
            sort(m[j].begin(), m[j].end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            int s = m[j].size();
            vector<int> temp;
            for(int i=0; i<s; i++){
                temp.push_back(m[j][i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};