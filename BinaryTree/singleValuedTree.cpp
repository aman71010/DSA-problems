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

class Solution{
    public:
    int singlevalued(Node *root){
        int ans = 0;
        solve(root, ans);
        return ans;
    }
    
    int solve(Node* root, int &ans){
        if(!root) return -1;
        if(!root->left && !root->right){
            ans++;
            return root->data;
        }
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        if((l==-1 && r==root->data) || (r==-1 && l==root->data) || (l == root->data && r == root->data)){
            ans++;
            return root->data;
        }
        return -2;
    }
};

class Solution{
    public:
    int singlevalued(Node *root){
        int ans = 0;
        solve(root, ans);
        return ans;
    }
    
    bool solve(Node* root, int &ans){
        if(!root) return 1;
        bool l = solve(root->left, ans);
        bool r = solve(root->right, ans);
        if(l == false || r == false)
            return 0;
        if(root->left && root->data != root->left->data)
            return 0;
        if(root->right && root->data != root->right->data)
            return 0;
        ans++;
        return true;
    }
};