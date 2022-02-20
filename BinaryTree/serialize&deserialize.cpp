#include<bits\stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        if(!root) return {-1};
        vector<int> ser;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr)
                ser.push_back(curr->data);
            else
                ser.push_back(-1);
            if(curr && curr->left){
                q.push(curr->left);
            }
            else if(curr)
                q.push(NULL);
            if(curr && curr->right)
                q.push(curr->right);
            else if(curr)
                q.push(NULL);
        }
        return ser;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &a){
        if(a[0]==-1) return NULL;
        Node* root = new Node(a[0]);
        queue<Node*> q;
        q.push(root);
        int i=1;
        while(i<a.size()){
            Node* curr = q.front();
            q.pop();
            if(a[i]!=-1){
                Node* left = new Node(a[i]);
                curr->left = left;
                q.push(left);
            }
            if(a[i+1]!=-1){
                Node* right = new Node(a[i+1]);
                curr->right = right;
                q.push(right);
            }
            i = i+2;
        }
        return root;
    }

};

//------------------------------------------------------------------------------------------------------------------

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s = "";
        preorder(root, s);
        //cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        vector<string> num;
        string temp = "";
        for(int i=0; i<data.length(); i++){
            if(data[i]==','){
                num.push_back(temp);
                temp = "";
            }
            else{
                temp += data[i];
            }
        }
        int i = 0;
        return buildTree(num, i);
    }

    void preorder(Node* root, string &s){
        if(!root){
            s += "N,";
            return;
        }
        s += to_string(root->data) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    Node* buildTree(vector<string> &num, int &i){
        if(num[i]=="N"){
            i++;
            return NULL;
        }
        Node* root = new Node(stoi(num[i++]));
        root->left = buildTree(num, i);
        root->right = buildTree(num, i);
        return root;
    }

};


