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

    //------------------------------------O(n*n)---------------------------------------------
    void findMinMax(Node* root, int *minm, int *maxm, int hd){
        if(!root) return;
        if(hd<*minm) *minm = hd;
        else if(hd>*maxm) *maxm = hd;
        findMinMax(root->left, minm, maxm, hd-1);
        findMinMax(root->right, minm, maxm, hd+1);
    }

    void getElement(Node* root, vector<int> &res, int lineNum, int hd){
        if(!root) return;
        if(lineNum==hd)
            res.push_back(root->data);
        getElement(root->left, res, lineNum, hd-1);
        getElement(root->right, res, lineNum, hd+1);
    }

    vector<int> verticalOrder(Node *root){
        vector<int> res;
        int minm = 0, maxm = 0;
        findMinMax(root, &minm, &maxm, 0);
        for(int lineNum=minm; lineNum<=maxm; lineNum++){
            getElement(root, res, lineNum, 0);
        }
        return res;
    }

    //-------------------------------------O(n)---------------------------------------------------

    vector<int> verticalOrder(Node *root){
        vector<int> res;
        if(!root) return res;
        unordered_map<int, vector<int>> um;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int minm = 0, maxm = 0;
        while(!q.empty()){
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            um[hd].push_back(curr->data);
            if(curr->left)
                q.push({curr->left, hd-1});
            if(curr->right)
                q.push({curr->right, hd+1});
            if(hd<minm)
                minm = hd;
            else if(hd>maxm)
                maxm = hd;
        }

        for(int lineNum=minm; lineNum<=maxm; lineNum++){
            vector<int> temp = um[lineNum];
            int s = temp.size();
            for(int i=0; i<s; i++){
                res.push_back(temp[i]);
            }
        }

        return res;
        
    }
};