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

class Solution{
    public:
    // Return the size of the largest sub-tree which is also a BST
    struct Info {
        int size;
        int maxm;
        int minm;
        int ans;
        bool isBST;
    };
    
    Info solve(Node* root){
        if(!root){
            Info temp;
            temp.size = 0;
            temp.maxm = INT_MIN;
            temp.minm = INT_MAX;
            temp.ans = 0;
            temp.isBST = true;
            return temp;
        }
        if(!root->left && !root->right){
            Info temp;
            temp.size = 1;
            temp.maxm = root->data;
            temp.minm = root->data;
            temp.ans = 1;
            temp.isBST = true;
            return temp;
        }
        Info l = solve(root->left);
        Info r = solve(root->right);
        Info retVar;
        retVar.size = l.size + r.size + 1;
        if(l.isBST && r.isBST && l.maxm < root->data && r.minm > root->data){
            retVar.maxm = max(l.maxm, max(r.maxm, root->data));
            retVar.minm = min(l.minm, min(r.minm, root->data));
            retVar.ans = retVar.size;
            retVar.isBST = true;
            return retVar;
        }
        retVar.ans = max(l.ans, r.ans);
        retVar.isBST = false;
        return retVar;
    }

    int largestBst(Node *root){
        Info res = solve(root);
    	return res.ans;
    }
};