#include<bits\stdc++.h>
using namespace std;

//Structure of a node is as following
struct Node{
     int data;
     struct Node* left;
     struct Node* right;
};


// T-> O(n) S-> O(n)
class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    int findDist(Node* root, int a, int b) {
        int ans = 0;
        getDistance(root, a, b, ans);
        return ans;
    }

    int getDistance(Node* root, int a, int b, int &ans){
        if(!root) return -1;
        if(root->data == a){
            int d = disDown(root, b);
            if(d != -1){
                ans = d;
                return -1;
            }
            return 0;
        }
        int dl = getDistance(root->left, a, b, ans);
        if(dl != -1){
            if(root->data == b){
                ans = dl+1;
                return -1;
            } else {
                int d = disDown(root->right, b);
                if(d != -1){
                    ans = d+2+dl;
                    return -1;
                }
                return dl+1;
            }
        }
        int dr = getDistance(root->right, a, b, ans);
        if(dr != -1){
            if(root->data == b){
                ans = dr+1;
                return -1;
            } else {
                int d = disDown(root->left, b);
                if(d != -1){
                    ans = d+2+dr;
                    return -1;
                }
                return dr+1;
            }
        }
        return -1;
    }

    int disDown(Node* root, int k){
        if(!root) return -1;
        if(root->data == k) return 0;
        int l, r;
        l = disDown(root->left, k);
        if(l == -1)
            r = disDown(root->right, k);
        if(l != -1) return l+1;
        if(r != -1) return r+1;
        return -1;
    }

};

class Solution{
    public:

    Node* lca(Node* root ,int n1 ,int n2 ){
        bool v1 = false, v2 = false;
        Node *res = findLca(root, n1, n2, v1, v2);
        if(v1&&v2 || v1&&find(root, n2) || v2&&find(root, n1))
            return res;
        return NULL;
    }

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

    int findDist(Node* root, int a, int b) {
        Node* node = lca(root, a, b);
        return disDown(node, a) + disDown(node, b);
    }

    int disDown(Node* root, int k){
        if(!root) return -1;
        if(root->data == k) return 0;
        int l, r;
        l = disDown(root->left, k);
        if(l == -1)
            r = disDown(root->right, k);
        if(l != -1) return l+1;
        if(r != -1) return r+1;
        return -1;
    }
};