#include<bits\stdc++.h>
using namespace std;


class WordDictionary {
public:
    unordered_map<int, vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        int n = word.length();
        if(mp.find(n)==mp.end())
            return false;
        vector<string> temp = mp[n];
        for(int i=0; i<temp.size(); i++){
            int j = 0;
            for( ; j<n; j++){
                if(word[j]==temp[i][j] || word[j]=='.')
                    continue;
                else
                    break;
            }
            if(j==n) return true;
        }
        return false;
    }
};


// using trie efficient approach
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
            if(key[i]!='.'){
                if(!node->children[key[i]-'a'])
                    return false;
                node = node->children[key[i]-'a'];
            }
            else{
                for(int j=0; j<26; j++){
                    if(node->children[j] && search(node->children[j], key.substr(i+1)))
                        return true;
                }
                return false;
            }
        }
        return node->isEndOfWord;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        root->insert(root, word);
    }
    
    bool search(string word) {
        return root->search(root, word);
    }
};