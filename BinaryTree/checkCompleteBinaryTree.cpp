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
    // iterative approach using level order traversal
    //-----------t = O(N) s = O(N) -----------------------------------
    bool isCompleteBT(Node* root){
        if(root == NULL) return false;
        queue<Node*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                if(flag) return false;
                q.push(curr->left);
            } else {
                flag = true;
            }
            if(curr->right){
                if(flag) return false;
                q.push(curr->right);
            } else {
                flag = true;
            }
        }
        return true;
    }

    // recursive approach 
    //-----------t = O(N) s = O(N) -----------------------------------

    int countNodes(Node* root){
        if(root == NULL) return 0;
        return (1+countNodes(root->left)+countNodes(root->right));
    }

    bool checkCompleteBT(Node* root, int ind, int totalNodes){
        if(root == NULL) return true;
        if(ind>=totalNodes)
            return false;
        return checkCompleteBT(root->left, 2*ind+1, totalNodes) && checkCompleteBT(root->right, 2*ind+2, totalNodes);
    }

    bool isCompleteBT(Node* root){
        int totalNodes = countNodes(root);
        return checkCompleteBT(root, 0, totalNodes);
    }
};