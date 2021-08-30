#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution 
{
    public:
    // using two stack
    vector<int> postOrder(Node* root)
    {
        if(!root) return {};
        vector<int> res;
        stack<Node*> s1, s2;
        s1.push(root);
        while(!s1.empty()){
            Node *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left)
                s1.push(curr->left);
            if(curr->right)
                s1.push(curr->right);
        }

        while(!s2.empty()){
            Node *curr = s2.top();
            s2.pop();
            res.push_back(curr->data);
        }
        return res;
    }

    //using one stack

    // vector<int> postOrder(Node* root)
    // {
        
    // }
};