#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
  public:
    // T-> O(n) S-> O(n) recurrsive
    vector<int> topView(Node *root)
    {
        unordered_map<int, pair<int,int>> um;
        vector<int> res;
        int minHD = 0, maxHD = 0;
        getTopView(root, um, 0, 1, minHD, maxHD);
        for(int j=minHD; j<=maxHD; j++)
            res.push_back(um[j].first);
        return res;
    }

    void getTopView(Node* root, unordered_map<int, pair<int,int>> &um, int hd, int l, int &minHD, int &maxHD){
        if(!root) return;
        maxHD = max(maxHD, hd);
        minHD = min(minHD, hd);
        if(um.count(hd)==0)
            um[hd] = {root->data, l};
        else if(um[hd].second>l)
            um[hd] = {root->data, l};
        getTopView(root->left, um, hd-1, l+1, minHD, maxHD);
        getTopView(root->right, um, hd+1, l+1, minHD, maxHD);
    }
};

class Solution {
  public:
    // T-> O(n) S-> O(n) using unordered_map

    vector<int> topView(Node *root)
    {
        if(!root) return {};
        unordered_map<int, int> m;
        vector<int> ans;
        int maxHD = 0, minHD = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node *c = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(m.count(hd) == 0)
                m[hd] = c->data;
            if(c->left)
                q.push({root->left, hd-1});
            if(c->right)
                q.push({root->right, hd+1});
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);
        }
        for(int j=minHD; j<=maxHD; j++)
            ans.push_back(m[j]);
        return ans;
    }

};

class Solution {
  public:
    // T-> O(n) S-> O(n) using stack
    vector<int> topView(Node *root)
    {
        if(!root) return {};
        vector<int> ans;
        vector<int> right;
        int maxHD = 0, minHD = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        stack<int> left;
        left.push(root->data);
        while(!q.empty()){
            Node *c = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(minHD > hd){
                left.push(c->data);
                minHD = hd;
            }   
            if(maxHD < hd){
                right.push_back(c->data);
                maxHD = hd;
            }
            if(c->left)
                q.push({root->left, hd-1});
            if(c->right)
                q.push({root->right, hd+1});
        }
        while(!left.empty()){
            ans.push_back(left.top());
            left.pop();
        }
        for(int i=0; i<right.size(); i++){
            ans.push_back(right[i]);
        }
        return ans;
    }
};