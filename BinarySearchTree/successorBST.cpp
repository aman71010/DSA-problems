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
    // returns the inorder successor of the Node x in BST (rooted at 'root')

    // --------------t-> O(H) and s->O(1)---------------------
    Node* getMinimum(Node *node){
        if(!node) return NULL;
        Node *curr = node;
        while(curr->left)
            curr = curr->left;
        return curr;
    }
    
    Node* inOrderSuccessor(Node *root, Node *x)
    {
        if(x->right!=NULL)
            return getMinimum(x->right);
        else {
            Node* succ = NULL;
            while(root){
                if(root->data>x->data){
                    succ = root;
                    root = root->left;
                }
                else if(root->data < x->data)
                    root = root->right;
                else
                    break;
            }
            return succ;
        }
    }
    
};