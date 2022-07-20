#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// T-> O(N) S-> O(N)
class Solution {
  public:
    int minTime(Node* root, int target){
        unordered_map<Node*, Node*> par;
        unordered_map<Node*, bool> burn;
        queue<Node*> q;
        q.push(root);
        par[root] = NULL;
        Node* tar = NULL;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            burn[curr] = false;
            if(curr->data == target)
                tar = curr;
            if(curr->left){
                q.push(curr->left);
                par[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                par[curr->right] = curr;
            }
        }
        int ans = -1;
        q.push(tar);
        burn[tar] = 1;
        while(!q.empty()){
            int n = q.size();
            ans++;
            while(n--){
                Node* curr = q.front();
                q.pop();
                Node* parent = par[curr];
                if(parent && burn[parent] == false){
                    q.push(parent);
                    burn[parent] = true;
                }
                if(curr->left && burn[curr->left] == false){
                    q.push(curr->left);
                    burn[curr->left] = true;
                }
                if(curr->right && burn[curr->right] == false){
                    q.push(curr->right);
                    burn[curr->right] = true;
                }
            }
        }
        return ans;
    }
};