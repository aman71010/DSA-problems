# include<bits\stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution 
{
    public:
    //iterative
    int countLeaves(Node* root){
        if(root == NULL) return 0;
        int ans = 0;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            if(curr->left == NULL && curr->right == NULL)
                ans++;
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
        } 
        return ans;
    }

    //recursive
    int countLeaves(Node* root){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }


};

int main(){
    return 0;
}