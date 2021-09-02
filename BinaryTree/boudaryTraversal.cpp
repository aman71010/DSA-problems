#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
};


class Solution 
{
    public:

    void boundaryLeft(Node *root, vector<int> &res){
        if(!root) return;
        if(root->left){
            res.push_back(root->data);
            boundaryLeft(root->left, res);
        }
        else if(root->right){
            res.push_back(root->data);
            boundaryLeft(root->right, res);
        }
    }

    void boundaryRight(Node *root, vector<int> &res){
        if(!root) return;
        if(root->right){
            boundaryRight(root->right, res);
            res.push_back(root->data);
        }
        else if(root->left){
            boundaryRight(root->left, res);
            res.push_back(root->data);
        }
    }

    void findLeafNode(Node *root, vector<int> &res){
        if(!root) return;
        findLeafNode(root->left, res);
        if(!root->left && !root->right)
            res.push_back(root->data);
        findLeafNode(root->right, res);
    }

    vector <int> printBoundary(Node *root){
        if(!root)
            return {};
        vector <int> res;
        res.push_back(root->data);
        boundaryLeft(root->left, res);
        findLeafNode(root->left, res);
        findLeafNode(root->right, res);
        boundaryRight(root->right, res);
        return res;
    }
};