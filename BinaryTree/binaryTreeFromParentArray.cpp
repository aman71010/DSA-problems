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


// T-> O(n) S-> O(n)
class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int n){
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++)
            mp[parent[i]].push_back(i);
        Node* root = new Node(mp[-1][0]);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            int s = mp[curr->data].size();
            if(s > 0){
                Node *l, *r;
                if(s == 1){
                    l = new Node(mp[curr->data][0]);
                    r = NULL;
                } else if(s == 2) {
                    l = new Node(mp[curr->data][0]);
                    r = new Node(mp[curr->data][1]);
                }
                curr->left = l;
                curr->right = r;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return root;
    }
};


