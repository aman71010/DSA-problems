#include<bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    public:

    //------------------------- T->O(n) but three traversal of bTree and extra space for vector-----------------
    bool findPath(Node* root, vector<Node*> &path, int n){
        if(!root) return 0;
        path.push_back(root);
        if(root->data==n)
            return 1;
        if((root->left && findPath(root->left, path, n)) || (root->right && findPath(root->right, path, n)))
            return 1;
        path.pop_back();
        return 0;
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
        vector<Node*> path1, path2;
        if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
            return NULL;
        int i;
        for(i=0; i<path1.size() && i<path2.size(); i++){
            if(path1[i]->data!=path2[i]->data)
                break;
        }
        return path1[i-1];
    }

    //---- Better approach T->O(n) and single traversal and no extra space other than recursive call stack-----------------

    Node* findLca(Node* root, int n1, int n2, bool &v1, bool &v2){
        if(!root) return NULL;
        if(root->data==n1){
            v1 = true;
            return root;
        }
        if(root->data==n2){
            v2 = true;
            return root;
        }
        Node* leftLca = findLca(root->left, n1, n2, v1, v2);
        Node* rightLca = findLca(root->right, n1, n2, v1, v2);
        if(leftLca && rightLca)
            return root;
        return leftLca ? leftLca : rightLca;
    }

    bool find(Node* root, int n){
        if(!root) return 0;
        if(root->data==n || find(root->left, n) || find(root->right, n))
            return 1;
        return 0;
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
        bool v1 = false, v2 = false;
        Node *res = findLca(root, n1, n2, v1, v2);
        if(v1&&v2 || v1&&find(root, n2) || v2&&find(root, n1))
            return res;
        return NULL;
    }
};

class Solution{
    public:
    void check(Node* root ,int n1 ,int n2, bool &v1, bool &v2){
        if(!root) return;
        if(root->data == n1)
            v1 = 1;
        else if(root->data == n2)
            v2 = 1;
        check(root->left, n1, n2, v1, v2);
        check(root->right, n1, n2, v1, v2);
    }

    Node* findLca(Node* root, int n1, int n2){
        if(!root) return NULL;
        if(root->data==n1)
            return root;
        if(root->data==n2)
            return root;
        Node* leftLca = findLca(root->left, n1, n2);
        Node* rightLca = findLca(root->right, n1, n2);
        if(leftLca && rightLca)
            return root;
        return leftLca ? leftLca : rightLca;
    }

    Node* lca(Node* root ,int n1 ,int n2 ){
        bool v1 = false, v2 = false;
        check(root, n1, n2, v1, v2);
        if(!v1 && !v2)
            return NULL;
        if(!v1 || !v2)
            return NULL;
        return findLca(root, n1, n2);
    }
};