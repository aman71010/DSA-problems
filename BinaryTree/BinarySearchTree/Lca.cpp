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
    //----------recusive solution t-> O(H) aux space-> O(H)--------

    Node* LCA(Node *root, int n1, int n2) {
    if(root == NULL) return NULL;
            if(root == NULL) return NULL;
            int rd = root->data;
            if(rd<n1 && rd <n2)
                return LCA(root->right, n1, n2);
            if(rd>n1 && rd>n2)
                return LCA(root->left, n1, n2); 
            return root;
    }

    //----------iterative solution t-> O(H) aux space-> const--------

    Node* LCA(Node *root, int n1, int n2) {
        Node* curr = root;
        while(curr){
            if(curr->data > n1 && curr->data > n2)
                curr = curr->left;
            else if(curr->data < n1 && curr->data < n2)
                curr = curr->right;
            else
                break;
        }
        return curr;
    }
};