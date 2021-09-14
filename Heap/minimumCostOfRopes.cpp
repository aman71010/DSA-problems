#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //------------------------- t-> O(nlog(n)) and s-> O(n) ----------------------------
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr, arr+n);
        while(minHeap.size() > 1){
           long long fMin = minHeap.top();
           minHeap.pop();
           long long sMin = minHeap.top();
           minHeap.pop();
           res += (fMin+sMin);
           minHeap.push(fMin+sMin);
        }
        return res;
    }
};