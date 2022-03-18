#include<bits\stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;

    struct Node {
        int key, value;
        Node *next, *prev;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = prev = NULL;
        }
    };
    
    unordered_map<int, Node*> mp;
    Node *dummy, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->dummy = new Node(-1, -1);
        this->tail = dummy;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            updataNode(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->value = value;
            updataNode(mp[key]);
        } else {
            Node *node = new Node(key, value);
            updateTail(node);
            mp[key] = node;
            if(mp.size()>capacity){
                Node* node = dummy->next;
                Node* next = node->next;
                dummy->next = next;
                next->prev = dummy;
                node->next = NULL;
                node->prev = NULL;
                auto it = mp.find(node->key);
                mp.erase(it);
                delete(node);
            }
        }
    }

     void updataNode(Node* n){
        if(n==tail) return;
        Node* next = n->next;
        Node* prev = n->prev;
        prev->next = next;
        next->prev = prev;
        n->next = NULL;
        n->prev = NULL;
        updateTail(n);
    }

    void updateTail(Node* n){
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */