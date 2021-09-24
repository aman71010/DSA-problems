#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //-------------------------t = O(klog(k) + (n-k)log(k) + klog(k)) ---------------------
    vector<int> kLargest(int arr[], int n, int k){
        vector<int> res;
    	priority_queue<int, vector<int>, greater<int>> minHeap(arr, arr+k);
        for(int i=k; i<n; i++){
            if(arr[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        for(int i=0; i<k; i++){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        sort(res.rbegin(), res.rend());
        return res;
    }
    
    //-------------------------t = O(klog(k) + (n-k)log(k) + klog(k)) ---------------------
    vector<int> KSmallest(int arr[], int n, int k){
    	vector<int> res;
    	priority_queue<int, vector<int>> maxHeap(arr, arr+k);
        for(int i=k; i<n; i++){
            if(arr[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        for(int i=0; i<k; i++){
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        sort(res.rbegin(), res.rend());
        return res;
    }
};