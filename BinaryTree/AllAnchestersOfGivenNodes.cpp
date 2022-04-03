#include<bits\stdc++.h>
using namespace std;

//Structure of a node is as following
struct Node{
     int data;
     struct Node* left;
     struct Node* right;
};

class Solution{
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target){
        vector<int> res;
        solve(root, target, res);
        return res;
    }
    
    bool solve(Node* root, int target, vector<int> &res){
        if(!root) return 0;
        if(root->data == target) return 1;
        bool found = false;
        found = found || solve(root->left, target, res);
        found = found || solve(root->right, target, res);
        if(found) res.push_back(root->data);
        return found;
    }
};


class Solution{
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target){
        vector<int> res;
        solve(root, target, res);
        return res;
    }
    
    bool solve(Node* root, int target, vector<int> &res){
        if(!root) return 0;
        if(root->data == target) return 1;
        if(solve(root->left, target, res) || solve(root->right, target, res)){
            res.push_back(root->data);
            return 1;
        }
        return false;
    }
};