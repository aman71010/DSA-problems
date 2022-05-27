#include<bits\stdc++.h>
using namespace std;


struct TrieNode {
    TrieNode* children[26];
    int freq;
    TrieNode(){
        for(int i=0; i<26; i++)
            children[i] = NULL;
        freq = 0;
    }
};

// T-> O(n*m) where m is maximum length of string in arr
class Solution{   
public:
    TrieNode* insert(TrieNode* root, string key){
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(!node->children[key[i]-'a'])
                node->children[key[i]-'a'] = new TrieNode();
            node = node->children[key[i]-'a'];
            node->freq++;
        }
        return root;
    }
    
    int klengthpref(string arr[], int n, int k, string str){
        TrieNode* root = new TrieNode();
        for(int i=0 ;i<n; i++){
            root = insert(root, arr[i]);
        }
        for(int i=0; i<k; i++){
            if(!root->children[str[i]-'a'])
                return 0;
            root = root->children[str[i]-'a'];
        }
        return root->freq;
    }
};

//another approach without trie
//T-> O(n*k) 