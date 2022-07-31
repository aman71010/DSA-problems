#include<bits\stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct compare {
    bool operator()(Node* a,  Node* b){
        return a->data > b->data;
    }
};

class Solution 
{
    public:
    //Function to merge K sorted linked list.
    //-----------t = O(Nlog(k)) s = O(k)  where N = k*n-----------------------------------
    Node * mergeKLists(Node *arr[], int K){
        Node *prev = NULL, *head = NULL;
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for(int i=0; i<K; i++){
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()){
            Node* curr = minHeap.top();
            minHeap.pop();
            if(head == NULL)
                head = curr;
            else
                prev->next = curr;
            prev = curr;
            if(curr->next){
                minHeap.push(curr->next);
            }
        }
        return head;
    }
};