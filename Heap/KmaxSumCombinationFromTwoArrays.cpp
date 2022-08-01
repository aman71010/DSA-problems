#include<bits\stdc++.h>
using namespace std;

class Solution {
    public:
    //T->O(nlogk)  S->O(n)
    vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
        vector<int> res;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>> maxHeap;
        for(int i=n-1; i>=0; i--)
            maxHeap.push({a[i]+b[n-1], {i, n-1}});
        while(!maxHeap.empty() && k--){
            auto t = maxHeap.top();
            maxHeap.pop();
            res.push_back(t.first);
            int i = t.second.first, j = t.second.second;
            if(j!=0)
                maxHeap.push({a[i]+b[j-1], {i,j-1}});
        }
        return res;
    }
};