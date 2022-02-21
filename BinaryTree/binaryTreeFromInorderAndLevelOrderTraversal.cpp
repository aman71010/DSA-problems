#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// T-> O(N^2) S->O(N)
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){
    unordered_map<int, int> ind;
    for(int i=0; i<n; i++)
        ind[levelOrder[i]] = i;
    return constructTree(inorder, levelOrder, 0, n-1, ind);
}

Node* constructTree(int inorder[], int levelOrder[], int start, int end, unordered_map<int, int> &ind){
    if(start>end)
        return NULL;
    int minIdx = start;
    for(int i=start+1; i<=end; i++){
        int temp = inorder[i];
        if(ind[inorder[minIdx]] > ind[temp])
            minIdx = i;
    }
    Node* root = new Node(inorder[minIdx]);
    if(start==end) return root;
    root->left = constructTree(inorder, levelOrder, start, minIdx-1, ind);
    root->right = constructTree(inorder, levelOrder, minIdx+1, end, ind);
    return root;
}