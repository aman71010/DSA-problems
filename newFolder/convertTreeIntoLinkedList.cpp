#include<bits\stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left,  *right;
};

class Solution{
    public:

    void getMaxLevel(Node* root, int lvl, int &maxlvl){
        if(!root) return;
        maxlvl = max(lvl, maxlvl);
        getMaxLevel(root->left, lvl+1, maxlvl);
        getMaxLevel(root->right, lvl+1, maxlvl);
    }

    Node* solve(Node* root, int l, int h){
        if(!root) return root ;
        int maxLevel =  1;
        getMaxLevel(root, 1, maxLevel);
        if(l>maxLevel) return NULL;
        int currLevel = 1;
        queue<Node*> q;
        q.push(root);
        Node* prev = NULL;
        Node* newHead = NULL;
        while (!q.empty()){
            int size = q.size();
            while(size--){
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(l <= currLevel && currLevel <= h){
                    if(!prev)
                        newHead = curr;
                    else
                        prev->right = curr;
                    prev = curr;
                }
            }
            currLevel++;
        }
        prev->right = NULL;
        // Node *currNode = newHead;
        // while(currNode){
        //     cout << currNode->data << " ";
        //     currNode = currNode->right;
        // }
        return newHead;
    }

};