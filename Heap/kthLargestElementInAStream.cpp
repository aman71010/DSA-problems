#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //--------------t = O(nlogn) aux = O(K)-------------------
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(int i=1; i<k; i++){
            res.push_back(-1);
            minHeap.push(arr[i-1]);
        }
        minHeap.push(arr[k-1]);
        res.push_back(minHeap.top());
        for(int i=k; i<n; i++){
            if(arr[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            res.push_back(minHeap.top());
        }
        return res;
    }
};