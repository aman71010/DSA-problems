#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

vector<int> diagonal(Node *root){
    if(!root) return {};
    vector<int> res;
    queue<Node*> q;
    Node* curr = root;
    while(curr || !q.empty()){
        if(!q.empty()){
            res.push_back(q.front()->data);
            if(q.front()->left)
                curr = q.front()->left;
            q.pop();
        }
        while(curr){
            q.push(curr);
            curr = curr->right;
        }
    }
    return res;
}

vector<int> diagonal(Node *root){
    if(!root) return {};
    vector<int> res;
    queue<Node*> q;
    Node* curr = root;
    while(curr || !q.empty()){
        if(curr){
            res.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);
            curr = curr->right;
        }
        else{
            curr = q.front();
            q.pop();
        }
    }
    return res;
}

