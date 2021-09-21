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
    bool isHeap(Node* root){
        if(root == NULL) return true;
        queue<Node*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                if(flag || curr->left->data >= curr->data) 
                    return false;
                q.push(curr->left);
            } else {
                flag = true;
            }
            if(curr->right){
                if(flag || curr->right->data >= curr->data) 
                    return false;
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

    bool checkHeap(Node* root, int ind, int totalNodes){
        if(root == NULL) return true;
        if(ind>=totalNodes)
            return false;
        if(root->left){
            if(root->left->data >= root->data)
                return false;
        }
        if(root->right){
            if(root->right->data >= root->data)
                return false;
        }
        return checkHeap(root->left, 2*ind+1, totalNodes) && checkHeap(root->right, 2*ind+2, totalNodes);
    }
    
    bool isHeap(struct Node* root) {
        int totalNodes = countNodes(root);
        return checkHeap(root, 0, totalNodes);
    }
};