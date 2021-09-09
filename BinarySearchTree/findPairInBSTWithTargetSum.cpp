#include<bits\stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution 
{
    public:
    // root : the root Node of the given BST
    // target : the target sum

    // ----------------using extra space other than O(H)---------------------

    void inOrder(Node *root, vector<int> &SArr){
        if(!root) return;
        inOrder(root->left, SArr);
        SArr.push_back(root->data);
        inOrder(root->right, SArr);
    }

    int checkTarget(vector<int> &arr, int sum){
        int l = 0, h = arr.size()-1;
        while(l<h){
            if(arr[l]+arr[h]<sum)
                h--;
            else if(arr[l]+arr[h]>sum)
                l++;
            else
                return 1;
        }
        return 0;
    }

    int isPairPresent(struct Node *root, int target)
    {
        vector<int> res;
        inOrder(root, res);
        return checkTarget(res, target);
    }

    // ---------------------without extra space other than O(H)-----------------------------------

    int isPairPresent(struct Node *root, int target) {
        if(!root) return false;
        stack<Node*> st1, st2;
        Node *curr1 = root, *curr2 = root;
        int done1 = 0, done2 = 0, val1 = 0, val2 = 0;
        while(1){
            while(done1==0){
                if(curr1){
                    st1.push(curr1);
                    curr1 = curr1->left;
                }
                else{
                    if(st1.empty()){
                        done1 = 1;
                    }
                    else{
                        curr1= st1.top();
                        st1.pop();
                        val1 = curr1->data;
                        curr1 = curr1->right;
                        done1 = 1;
                    }
                }
            }

            while(done2==0){
                if(curr2){
                    st2.push(curr2);
                    curr2 = curr1->right;
                }
                else{
                    if(st2.empty()){
                        done2 = 1;
                    }
                    else{
                        curr2 = st2.top();
                        st2.pop();
                        val2 = curr2->data;
                        curr2 = curr2->left;
                        done2 = 1;
                    }
                }
            }

            if(val1!=val2 && val1+val2==target){
                return 1;
            }
            else if(val1+val2<target){
                done1 = 0;
            }
            else if(val1+val2>target){
                done2 = 0;
            }
            if(val1>=val2)
                return 0;

        }
    }
};