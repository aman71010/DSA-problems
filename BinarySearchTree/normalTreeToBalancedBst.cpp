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


void inorder(Node* root, vector<Node*>& nodes){
  if(!root) return;
  inorder(root->left, nodes);
  nodes.push_back(root);
  inorder(root->right, nodes);
}


Node* balancedBST(int l, int r, vector<Node*>& nodes){
  if(r<l) return NULL;
  int m = l+(r-l)/2;
  Node* root = nodes[m];
  root->left = balancedBST(l, m-1, nodes);
  root->right = balancedBST(m+1, r, nodes);
  return root;
}

// T-> O(n) and S-> O(n)
Node* buildBalancedTree(Node* root){
  if(!root) return NULL;
	vector<Node*> nodes;
  inorder(root, nodes);
  return balancedBST(0,nodes.size()-1, nodes);
}
