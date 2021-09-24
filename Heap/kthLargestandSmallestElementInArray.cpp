#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //-------------------------t = O(k + (n-k)log(k)) ---------------------
    int kthLargest(int arr[], int n, int k){
    	priority_queue<int, vector<int>, greater<int>> minHeap(arr, arr+k);
        for(int i=k; i<n; i++){
            if(arr[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        return minHeap.top();
    }
    
    //-------------------------t = O(k + (n-k)log(k)) ---------------------
    int kthSmallest(int arr[], int n, int k){
    	priority_queue<int, vector<int>> maxHeap(arr, arr+k);
        for(int i=k; i<n; i++){
            if(arr[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        return maxHeap.top();
    }
};