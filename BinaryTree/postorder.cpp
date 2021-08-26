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
    vector<int> postOrder(Node* root)
    {
        vector<int> res;
        Node *curr = root;
        stack<Node*> st;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            Node *topNode = st.top();
            st.pop();
            res.push_back(topNode->data);
            curr = topNode->right;
        }
        return res;
    }
};