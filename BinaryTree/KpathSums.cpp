#include<bits\stdc++.h>  
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Giving TLE
class Solution{
  public:
    int sumK(Node *root,int k){
        queue<pair<Node*, vector<int>>> q;
        int ans = 0;
        if(root->data == k) ans++;
        q.push({root, {root->data}});
        while(!q.empty()){
            pair<Node*, vector<int>> pr = q.front();
            q.pop();
            Node* curr = pr.first;
            vector<int> temp = pr.second;
            if(curr->left){
                int lData = curr->left->data;
                vector<int> lArr;
                lArr.push_back(lData);
                if(lData==k) ans++;
                for(int x: temp){
                    int y = lData+x;
                    if(y==k) ans++;
                    lArr.push_back(y);
                }
                q.push({curr->left, lArr});
            }
            if(curr->right){
                int rData = curr->right->data;
                vector<int> rArr;
                rArr.push_back(rData);
                if(rData==k) ans++;
                for(int x: temp){
                    int y = rData+x;
                    if(y==k) ans++;
                    rArr.push_back(y);
                }
                q.push({curr->right, rArr});
            }
        }
        return ans; 
    }
};

// T-> O(n*h*h) S-> O(h)
class Solution{
  public:
    int sumK(Node *root,int k){
        int ans = 0;
        vector<int> path;
        solve(root, path, k, ans);
        return ans;
    }

    void solve(Node* root, vector<int> &path, int k, int &ans){
        if(!root) return;
        path.push_back(root->data);
        solve(root->left, path, k, ans);
        solve(root->right, path, k, ans);
        int sum = 0;
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i];
            if(sum == k) ans++;
        }
        path.pop_back();
    }
};