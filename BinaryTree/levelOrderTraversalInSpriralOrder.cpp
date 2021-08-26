#include<bits\stdc++.h>
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
    //iterative (using deque)
    vector<int> findSpiral(Node *root){
        if(!root) return{}; 
        vector<int> res;
        deque<Node*> dq;
        dq.push_back(root);
        bool reverse = true;
        while(!dq.empty()){
            int n = dq.size();
            if(!reverse){
                for(int i = 0; i<n; i++){
                    Node* curr = dq.front();
                    if(curr->left)
                        dq.push_back(curr->left);
                    if(curr->right)
                        dq.push_back(curr->right);
                    res.push_back(curr->data);
                    dq.pop_front();
                }
                reverse = !reverse;
            } else {
                while(n--){
                    Node* curr = dq.back();
                    if(curr->right)
                        dq.push_front(curr->right);
                    if(curr->left)
                        dq.push_front(curr->left);    
                    res.push_back(curr->data);
                    dq.pop_back();
                }
                reverse = !reverse;
            }
        }
        return res;
    }

    //iterative (using stack)
    vector<int> findSpiral(Node *root){
        if(!root) return{}; 
        vector<int> res;
        stack<Node*> ls, rs;
        rs.push(root);
        while(!ls.empty() || !rs.empty()){
            while(!rs.empty()){
                Node* curr = rs.top();
                rs.pop();
                res.push_back(curr->data);
                if(curr->right)
                    ls.push(curr->right);
                if(curr->left)
                    ls.push(curr->left);
                   
            }
            while(!ls.empty()){
                Node* curr = ls.top();
                ls.pop();
                res.push_back(curr->data);
                if(curr->left)
                    rs.push(curr->left);
                if(curr->right)
                    rs.push(curr->right);
            }
        }
        return res;
    }

    //recursive
    


};

int main(){
    return 0;
}