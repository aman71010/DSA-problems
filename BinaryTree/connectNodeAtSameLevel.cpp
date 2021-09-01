#include<bits\stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};


class Solution
{
    public:
    //Function to connect nodes at same level.

    //T->O(n) S->O(n)
    void connect(Node *root)
    {
        if(!root) return;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        pair<Node*, int> prev = {NULL, -1};
        while (!q.empty())
        {
            pair<Node*, int> curr = q.front();
            q.pop();
            if(curr.second == prev.second)
                curr.first->nextRight = prev.first;
            else
                curr.first->nextRight = NULL;
            prev = curr;
            if(curr.first->right){
                q.push({curr.first->right, curr.second+1});
            }
            if(curr.first->left){
                q.push({curr.first->left, curr.second+1});
            }
        }
        return ; 
    }    
      

    //another solution T->O(n) S->O(n)
    void connect(Node *root){
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            Node* prev = NULL;
            while(size--){
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(prev)
                    prev->nextRight = curr;
                prev = curr;
            }
            prev->nextRight = NULL;
        }
        return;
    }

};
