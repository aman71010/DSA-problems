#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// T -> O(n)
int kthAncestor(Node *root, int k, int node){
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

int solve(Node *root, int k, int node, int &ans){
    if(!root) return -1;
    if(root->data == node)
        return 0;
    int dis = solve(root->left, k, node, ans);
    if(dis != -1){
        if(dis+1 == k)
            ans = root->data;
        return dis+1;
    }
    dis = solve(root->right, k, node, ans);
    if(dis != -1){
        if(dis+1 == k)
            ans = root->data;
        return dis+1;
    }
    return -1;
}

// T -> O(n) S-> O(n)
int kthAncestor(Node *root, int k, int node){
    vector<int> ancestors;
    solve(root, node, ancestors);
    if(k > ancestors.size()-1 || k<=0)
        return -1;
    return ancestors[ancestors.size()-1-k];
}

bool solve(Node *root, int node, vector<int> &ancestors){
    if(!root) return false;
    ancestors.push_back(root->data);
    if(root->data == node)
        return true;
    if(solve(root->left, node, ancestors) || solve(root->right, node, ancestors))
        return true;
    ancestors.pop_back();
    return false;
}