#include<bits\stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution 
{
    public:
    //recursive 
    int minDepth(Node *root) {
        if(!root) return 0; //corner case
        if(!root->left && !root->right)
            return 1;                 //base case
        int l = INT_MAX, r = INT_MAX;
        if(root->left)
            l = minDepth(root->left);
        if(root->right)
            r = minDepth(root->right);
        return min(l,r) + 1;
    }

    //iterative solution and optimized
    int minDepth(Node *root) {
        if(!root) return 0;
        pair<Node*, int> p;
        p.first = root;
        p.second = 1;
        queue<pair<Node*, int>> q;
        q.push(p);
        while(!q.empty()){
            Node* curr = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(!curr->left && !curr->right)
                return depth;
            if(curr->left){
                q.push(make_pair(curr->left, depth+1));
            }
            if(curr->right){
                q.push(make_pair(curr->right, depth+1));
            }
        }
    }
};