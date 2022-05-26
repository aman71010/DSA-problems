#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) s-> O(1) brute force

// T-> O(nlogn) s-> O(1)
class Solution{   
public:
    int minxorpair(int n, int arr[]){    
        sort(arr, arr+n);
        int res = INT_MAX;
        for(int i=0; i<n-1; i++){
            res = min(res, arr[i]^arr[i+1]);
        }
        return res;
    }
};


struct TrieNode {
    TrieNode* children[2];
    int value;
    TrieNode(){
        children[0] = children[1] = NULL;
        value = -1;
    }
    void insert(TrieNode* root, int key){
        TrieNode* node = root;
        for(int i=31; i>=0; i--){
            bool currentBit = (key&(1<<i));
            if(!node->children[currentBit])
                node->children[currentBit] = new TrieNode();
            node = node->children[currentBit];
        }
        node->value = key;
    }
};

// T-> O(n)
class Solution{   
public:

    int minXorUti(TrieNode* root, int key){
        TrieNode* node = root;
        for(int i=31; i>=0; i--){
            bool currentBit = (key&(1<<i));
            if(node->children[currentBit])
                node = node->children[currentBit];
            else if(node->children[1-currentBit])
                node = node->children[1-currentBit];
        }
        return key^node->value;
    }

    int minxorpair(int n, int arr[]){    
        TrieNode* root = new TrieNode();
        root->insert(root, arr[0]);
        int res = INT_MAX;
        for(int i=1; i<n; i++){
            res = min(res, minXorUti(root, arr[i]));
            root->insert(root, arr[i]);
        }
        return res;
    }
};