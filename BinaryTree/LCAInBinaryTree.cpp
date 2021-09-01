#include<bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    public:
    bool findPath(Node* root, vector<Node*> &path, int n){
        if(!root) return 0;
        path.push_back(root);
        if(root->data==n)
            return 1;
        if((root->left && findPath(root->left, path, n)) || (root->right && findPath(root->right, path, n)))
            return 1;
        path.pop_back();
        return 0;
    }

    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector<Node*> path1, path2;
        if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
            return NULL;
        int i;
        for(i=0; i<path1.size() && i<path2.size(); i++){
            if(path1[i]->data!=path2[i]->data)
                break;
        }
        return path1[i-1];
    }
};