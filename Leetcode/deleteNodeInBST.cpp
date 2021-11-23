#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    // recursive approach T->O(t) and s->O(t)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            if(!root->left && !root->right){
                delete(root);
                return NULL;
            }
            else if(!root->left || !root->right){
                TreeNode* temp = root->left ? root->left : root->right;
                delete(root);
                return temp;
            }
            else{
                TreeNode* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

    // iterative approach T->O(t) and s->O(1)
    TreeNode* deleteNode(TreeNode* root, int key){
        TreeNode* parent = NULL;
        TreeNode* curr = root;
        while(curr && curr->val != key){
            parent = curr;
            if(curr->val < key) curr = curr->right;
            else curr = curr->left;
        }
        if(!curr) return root;
        if(!curr->left || !curr->right){
            TreeNode* child = curr->left ? curr->left : curr->right;
            if(!parent) root = child;
            else if(parent->left == curr) parent->left = child;
            else parent->right = child;
        }
        else{
            TreeNode* temp = curr;
            parent = curr;
            curr = curr->right;
            while(curr->left){
                parent = curr;
                curr = curr->left;
            }
            temp->val = curr->val;
            if(parent->left == curr) parent->left = curr->right;
            else parent->right = curr->right;
            
        }
        delete(curr);
        return root;
    }

};