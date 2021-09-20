#include<bits\stdc++.h>
typedef pair<int, pair<int, int>> ppi;
using namespace std;

class Solution 
{
    public:
    // naive solution 
    // use sorting
    
    //-----------t = O(k*klog(k)) s = O(k*klog(k)) -------------------------------
    // recursive solution


    //Function to merge k sorted arrays.
    //-----------t = O(k*2log(k)) s = log(k) -----------------------------------
    //using heap
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
        for(int i=0; i<K; i++){
            minHeap.push({arr[i][0], {i, 0}});
        }
        while(!minHeap.empty()){
            ppi x = minHeap.top();
            minHeap.pop();
            res.push_back(x.first);
            int i = x.second.first, j = x.second.second;
            if(j+1<K){
                minHeap.push({arr[i][j+1], {i, j+1}});
            }
        }
        return res;
    }
};