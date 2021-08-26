#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution 
{
    public:
    // return true/false denoting whether the tree is Symmetric or not

    //recursive
    bool isMirror(Node *r1, Node* r2){
        if(!r1 && !r2) return true;
        if((r1 && r2) && r1->data==r2->data)
            return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
        return false;
    }

    bool isSymmetric(struct Node* root)
    {
	    if(!root) return true;
        return isMirror(root->left, root->right);
    }

    //iterative

    bool isSymmetric(struct Node* root)
    {
	    if(!root) return true;
        if(!root->left && !root->right)
            return true;
        queue<Node*> q;
        if(root->left && root->right){
            q.push(root->left);
            q.push(root->right);
        }
        else if(root->left || root->right)
            return false;
            
        Node *leftNode, *rightNode;
        while(!q.empty()){
            leftNode = q.front();
            q.pop();
            rightNode = q.front();
            q.pop();
            if(leftNode->data!=rightNode->data)
                return false;
            if(leftNode->left && rightNode->right){
                q.push(leftNode->left);
                q.push(rightNode->right);
            }
            else if(leftNode->left || rightNode->right)
                return false;
            if(leftNode->right && rightNode->left){
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            else if(leftNode->right || rightNode->left)
                return false;
        }
        return true;
    }
};