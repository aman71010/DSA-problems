#include<bits\stdc++.h>
using namespace std;

//Structure of a node is as following
struct Node{
     int data;
     struct Node* left;
     struct Node* right;
};

// naive T-> O(n^2) and S-> O(n)

// T-> O(n) and S-> O(n)
class Solution{
  public:
    void convertToMaxHeapUtil(Node* root){
      vector<int> inOrder;
      inorder(root, inOrder);
      int i = inOrder.size()-1;
      solve(root, inOrder, i);
    }    

    void inorder(Node* root, vector<int> &inOrder){
      if(!root) return;
      inorder(root->left, inOrder);
      inOrder.push_back(root->data);
      inorder(root->right, inOrder);
    }

    void solve(Node* root, vector<int> &arr, int& i){
      if(!root) return;
      root->data = arr[i--];
      solve(root->right, arr, i);
      solve(root->left, arr, i);
    }   
};
