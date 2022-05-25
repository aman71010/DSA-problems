#include<bits\stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
    void insert(TrieNode* root, string key){
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(!node->children[key[i]-'a'])
                node->children[key[i]-'a'] = new TrieNode();
            node = node->children[key[i]-'a'];
        }
        node->isEndOfWord = true;
    }
    bool search(TrieNode* root, string key){
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(!node->children[key[i]-'a'])
                return false;
            node = node->children[key[i]-'a'];
        }
        return node->isEndOfWord;
    }

    void display(TrieNode* root, string& s){
        if(root->isEndOfWord == true){
            cout << s << endl;
        }
        for(int i=0; i<26; i++){
            if(root->children[i]){
                s += ('a'+i);
                display(root->children[i], s);
            }
        }
        s.pop_back();
    }
};

class Solution{
    public:
        bool checkWord(string s, TrieNode* root){
            if(s.length() == 0) return true;
            for(int i=1; i<=s.length(); i++){
                if(root->search(root, s.substr(0, i)) && checkWord(s.substr(i, s.length()-i), root))
                    return true;
            }
            return false;
        }

        bool wordBreak(string s, vector<string>& wordDict){
            TrieNode* root = new TrieNode();
            for(int i=0; i<wordDict.size(); i++)
                root->insert(root, wordDict[i]);
            return checkWord(s, root);
        }
};