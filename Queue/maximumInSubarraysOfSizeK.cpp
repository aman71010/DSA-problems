#include<bits\stdc++.h>
using namespace std;

//T->O(n^2)  S->O(1) using two nested loop
//T->O(nlogk)  S->O(k) using maxHeap

//T->O(n)  S->O(k)
class Solution{
  public:
    vector<int> max_of_subarrays(int *arr, int n, int k){
        deque<int> dq(k);
        vector<int> res;
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        for(int i=k; i<n; i++){
            if(dq.front() == i-k)
                dq.pop_front();
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            res.push_back(arr[dq.front()]);
        }
        return res;
    }
};