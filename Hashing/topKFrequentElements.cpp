#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> topK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto x: mp)
            pq.push({x.second, x.first});
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


class Solution{
    public:
    vector<int> topK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto x: mp){
            pq.push({x.second, x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans(k);
        for(int i=k-1; i>=0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};