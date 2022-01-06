#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
  public:
    // T-> O(n) S-> O(n)
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        unordered_map<int, int> m;
        vector<int> res;
        queue<pair<Node*,int>> q;
        int minHD = 0, maxHD = 0;
        q.push({root,0});
        while(!q.empty()){
            Node* c = q.front().first;
            int hd = q.front().second;
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);
            q.pop();
            m[hd] = c->data;
            if(c->left)
                q.push({c->left, hd-1});
            if(c->right)
                q.push({c->right, hd+1});
        }
        for(int j=minHD; j<=maxHD; j++){
            res.push_back(m[j]);
        }
        return res;
    }
};