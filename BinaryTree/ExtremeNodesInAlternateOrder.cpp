#include<bits\stdc++.h>
using namespace std;

//Structure of a node is as following
struct Node{
     int data;
     struct Node* left;
     struct Node* right;
};


// T-> O(n) and S-> O(n) but uses extra vector.
class Solution{
  public:
    vector<int> ExtremeNodes(Node* root){
        vector<int> res;
        if(root == NULL) return res;
        queue<Node*>q;
        q.push(root);
        bool rightMost = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> levelNodes;
            while(n--){
                Node* curr = q.front();
                q.pop();
                levelNodes.push_back(curr->data);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            rightMost ? res.push_back(levelNodes[levelNodes.size()-1]): res.push_back(levelNodes[0]);
            rightMost = !rightMost;
        }
        return res;
    }
};

// T-> O(n) and S-> O(n).
class Solution{
  public:
    vector<int> ExtremeNodes(Node* root){
        vector<int> res;
        if(root == NULL) return res;
        queue<Node*>q;
        q.push(root);
        bool rightMost = true;
        while(!q.empty()){
            int n = q.size();
            int nodeCount = n;
            while(n--){
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(rightMost && n == 0)
                    res.push_back(curr->data);
                else if(!rightMost && n == nodeCount-1)
                    res.push_back(curr->data);
            }
            rightMost = !rightMost;
        }
        return res;
    }
};
