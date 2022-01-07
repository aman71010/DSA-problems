#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
    public:
    // T-> O(n) S-> O(h)
    bool findPath(Node* a, int b, vector<int> &res){
        if(!a) return false;
        res.push_back(a->data);
        if(a->data == b)
            return true;
        if(findPath(a->left, b, res) || findPath(a->right, b, res))
            return true;
        res.pop_back();
        return false;
    }

    vector<int> solvePath(Node* a, int b){
        vector<int> res;
        findPath(a, b, res);
        return res;
    }

    //-----------------------------------------------------------------------------
    // T-> O(n) S-> O(h)
    void findPath(Node* a, int b, bool &flag, vector<int> &res){
        if(!a) return;
        if(a->data == b){
            flag = true;
        }
        if(!flag && a->left)
            findPath(a->left, b, flag, res);
        if(!flag && a->right)
            findPath(a->right, b, flag, res);
        if(flag)
            res.push_back(a->data);
    }

    vector<int> solvePath(Node* a, int b){
        vector<int> res;
        findPath(a, b, res);
        int n = res.size();
        for(int i=0; i<n/2; i++)
            swap(res[i], res[n-i-1]);
        return res;
    }
};