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

class Solution {
  public:
    Node *prev, *first, *middle, *last;
    void correctBST( struct Node* root ){
        prev = first = middle = last = NULL;
        inorder(root);
        if(first && last)
            swap(first->data, last->data);
        else if(first && middle)
            swap(first->data, middle->data);
    }

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        if(prev && root->data < prev->data){
            if(!first){
                first = prev;
                middle = root;
            } else 
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
};