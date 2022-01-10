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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        int level = 0, ind = 0;
        while(!q.empty()){
            int n = q.size();
            int first, last;
            for(int i=1; i<=n; i++){
                Node *curr = q.front();
                q.pop();
                ans.push_back(curr->data);
                if(i==1)
                    first = ind;
                if(i==n)
                    last = ind;
                ind++;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(level%2==1){
                while(first<last){
                    swap(ans[first++], ans[last--]);
                }
            }
            level++;
        }
        return ans;
    }
};
