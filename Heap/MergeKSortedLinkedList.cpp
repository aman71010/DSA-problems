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
    //-----------t = O(Nlog(k)) s = log(k)  where N = k*n-----------------------------------
    Node * mergeKLists(Node *arr[], int K)
    {
        Node *curr = NULL, *head = NULL;
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for(int i=0; i<K; i++){
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()){
            Node* x = minHeap.top();
            minHeap.pop();
            if(curr == NULL){
                curr = x;
                head = curr;
            }
            else{
                curr->next = x;
                curr = curr->next;
            }
            if(x->next){
                minHeap.push(x->next);
            }
        }
        return head;
    }
};