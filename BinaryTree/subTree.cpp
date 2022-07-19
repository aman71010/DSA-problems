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
    //-----------------------O(m*n)---worst case---------------------------------------------
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
    }
};


class Solution{
  public:

    int height(Node* S){
        if(!S)  return 0;
        return max(height(S->left), height(S->right)) + 1;
    }

    int checkHeight(Node* T, Node* S, vector<Node*> &nodes, int h){
        if(!T)  return 0;
        int l = checkHeight(T->left, S, nodes, h);
        int r = checkHeight(T->right, S, nodes, h);
        int currHeight = max(l,r) + 1;
        if(S->data == T->data && currHeight == h)
            nodes.push_back(T);
        return currHeight;
    }

    bool isIdentical(Node *r1, Node *r2){
        if(!r1 && !r2) return 1;
        if(r1 && r2)
            return r1->data==r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
        return 0;
    }

    bool isSubTree(Node* T, Node* S) {
        if(!S) return 1;
        if(!T) return 0;
        int sHeight = height(S); 
        vector<Node*> nodes;
        checkHeight(T, S, nodes, sHeight);
        for(int i=0; i<nodes.size(); i++){
            if(isIdentical(nodes[i], S))
                return 1;
        }
        return 0;
    }
};

// T->O(N)
class Solution{
  public:

    void inorder(Node* root, string &str){
        if(!root){
            str += '#';
            return;
        }
        inorder(root->left, str);
        str += to_string(root->data);
        inorder(root->right, str);
    }

    void preorder(Node* root, string &str){
        if(!root){
            str += '#';
            return;
        }
        str += to_string(root->data);
        preorder(root->left, str);
        preorder(root->right, str);
    } 

    bool isSubTree(Node* T, Node* S) {
        if(!S) return 1;
        if(!T) return 0;
        string inT, inS, preT, preS;
        inorder(T, inT);
        inorder(S, inS);
        preorder(T, preT);
        preorder(S, preS);
        if(inT.find(inS) == string::npos)
            return false;
        if(preT.find(preS) == string::npos)
            return false;
        return true;
    }
};