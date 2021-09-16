#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //--------------t = O(nlogn) aux = O(n)-------------------
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int i=0; 
        while(i+1<k){
            res.push_back(-1);
            minHeap.push(arr[i]);
            i++;
        }
        minHeap.push(arr[i]);
        res.push_back(minHeap.top());
        i++;
        for(int j=i; j<n; j++){
            if(arr[j] > minHeap.top()){
                minHeap.pop();
                minHeap.push(arr[j]);
            }
            res.push_back(minHeap.top());
        }
        return res;
    }
};