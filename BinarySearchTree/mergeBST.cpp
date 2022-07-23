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

class Solution {
    public:
    vector<int> merge(Node *r1, Node *r2){
        vector<int> res;
        Node* c1 = r1;
        Node* c2 = r2;
        stack<Node*> st1, st2;
        while(c1 || c2 || !st1.empty() || !st2.empty()){
            while(c1){
                st1.push(c1);
                c1 = c1->left;
            }
            while(c2){
                st2.push(c2);
                c2 = c2->left;
            }
            Node *t1, *t2;
            if(!st1.empty() && !st2.empty()){
                t1 = st1.top();
                st1.pop();
                t2 = st2.top();
                st2.pop();
                if(t1->data < t2->data){
                    res.push_back(t1->data);
                    st2.push(t2);
                    c1 = t1->right;
                }
                else if(t1->data > t2->data){
                    res.push_back(t2->data);
                    st1.push(t1);
                    c2 = t2->right;
                }
                else{
                    res.push_back(t1->data);
                    res.push_back(t2->data);
                    c1 = t1->right;
                    c2 = t2->right;
                }
            }
            else if(!st1.empty()){
                t1 = st1.top();
                st1.pop();
                res.push_back(t1->data);
                c1 = t1->right;
            }
            else{
                t2 = st2.top();
                st2.pop();
                res.push_back(t2->data);
                c2 = t2->right;
            }
        }
        return res;
    }
};

class Solution
{
    public:
    vector<int> merge(Node *root1, Node *root2){
        vector<int> res;
        stack<Node*> st1, st2;
        Node *c1 =root1, *c2 = root2;
        while((c1||!st1.empty()) || (c2||!st2.empty())){
            while(c1){
                st1.push(c1);
                c1 = c1->left;
            }
            while(c2){
                st2.push(c2);
                c2 = c2->left;
            }
            if(!st1.empty() && !st2.empty()){
                Node* n1 = st1.top();
                Node* n2 = st2.top();
                if(n1->data < n2->data){
                    res.push_back(n1->data);
                    st1.pop();
                    c1 = n1->right;
                } else if(n1->data > n2->data){
                    res.push_back(n2->data);
                    st2.pop();
                    c2 = n2->right;
                } else{
                    res.push_back(n1->data);
                    res.push_back(n2->data);
                    st1.pop();
                    st2.pop();
                    c1 = n1->right;
                    c2 = n2->right;
                }
            }
            else if(!st1.empty()){
                Node* n1 = st1.top();
                st1.pop();
                res.push_back(n1->data);
                c1 = n1->right;
            }
            else if(!st2.empty()){
                Node* n2 = st2.top();
                st2.pop();
                res.push_back(n2->data);
                c2 = n2->right;
            }
        }
        return res;
    }
};