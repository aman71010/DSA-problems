#include<bits\stdc++.h>
using namespace std;

struct Node{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Solution{
  public:
    Node* addPolynomial(Node *p1, Node *p2){
        Node *dummy = new Node(0,0);
        Node *prev = dummy;
        while(p1 && p2){
            if(p1->pow == p2->pow){
                p1->coeff += p2->coeff;
                prev->next = p1;
                p1 = p1->next;
                p2 = p2->next;
            } else if(p1->pow > p2->pow){
                prev->next = p1;
                p1 = p1->next;
            } else {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }
        if(p1) prev->next = p1;
        else prev->next = p2;
        return dummy->next;
    }
};

