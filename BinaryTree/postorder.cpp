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
};

class Solution 
{
    public:
    // using two stack
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st1, st2;
        Node* curr = root;
        while(curr || !st1.empty()){
            while(curr){
                st1.push(curr);
                st2.push(curr);
                curr = curr->right;
            }
            Node* topNode = st1.top();
            st1.pop();
            curr = topNode->left;
        }
        while(!st2.empty()){
            res.push_back(st2.top()->data);
            st2.pop();
        }
        return res;
    }
};

class Solution 
{
    public:
    // using only one stack
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        Node* curr = root;
        while(curr || !st.empty()){
            while(curr){
                if(curr->right)
                    st.push(curr->right);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(curr->right && !st.empty() &&curr->right == st.top()){
                st.pop();
                st.push(curr);
                curr = curr->right;
            }else{
                res.push_back(curr->data);
                curr = NULL;
            }
            
        }
        return res;
    }
};