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
    int getLevelDiff(Node *root){
        int even = 0, odd = 0;
        int level = 0;
        solve(root, level, even, odd);
        return even-odd;
    }

    void solve(Node* root, int level, int &even, int &odd){
        if(!root) return;
        if(level%2 == 0)
            even += root->data;
        else
            odd += root->data;
        solve(root->left, level+1, even, odd);
        solve(root->right, level+1, even, odd);
    }
};