#include<bits\stdc++.h>  
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
    void transformTree(struct Node *root){
        int sum = 0;
        solve(root, sum);
    }
    
    void solve(Node* root, int &sum){
        if(!root) return;
        solve(root->right, sum);
        int temp = root->data;
        root->data = sum;
        sum += temp;
        if(root->left)
            solve(root->left, sum);
    }
};
