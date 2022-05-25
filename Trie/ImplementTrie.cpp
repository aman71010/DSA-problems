#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) s-> O(26)
struct Node{
    Node* links[26];
    bool flag;
    
    Node(){
        for(int i=0; i<26; i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containKey(char c){
        return links[c-'a'] != NULL;
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void setEndOfKey(){
        flag = true;
    }
    
    bool isEndOfKey(){
        return flag;
    }
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i]))
                node->put(word[i], new Node);
            node = node->get(word[i]);
        }
        node->setEndOfKey();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEndOfKey();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */