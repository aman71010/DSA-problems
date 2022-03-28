#include<bits\stdc++.h>
using namespace std;

// The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if(!head || head->next == head) return;
    Node *s, *f, *second, *curr;
    s = f = head;
    while(f->next != head && f->next->next != head){
        s = s->next;
        f = f->next->next;
    }
    second = curr = s->next;
    s->next = head;
    while(curr->next != head)
        curr = curr->next;
    curr->next = second;
    *head1_ref = head;
    *head2_ref = second;
}