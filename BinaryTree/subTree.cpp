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
    bool isIdentical(Node *r1, Node *r2)
    {
        if(!r1 && !r2) return 1;
        if(r1 && r2) {
            return r1->data==r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
        }
        return 0;
    }

    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        if(!T && !S) return 1;
        else if(!T || !S) return 0;
        queue<Node*> q;
        q.push(T);
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            if(curr->data == S->data){
                if(isIdentical(curr, S))
                    return 1;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

        return 0;

        //-----------------------O(m*n)---worst case---------------------------------------------
    }
};