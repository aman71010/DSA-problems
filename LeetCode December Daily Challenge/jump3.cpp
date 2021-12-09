#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // t-> O(n) s-> O(n)(considering recurrsive call stacks)

    bool canReach(vector<int>& arr, int start) {
        if(arr[start]<0)
            return false;
        if(arr[start]==0)
            return true;
        int lSide = start-arr[start];
        int rSide = start+arr[start];
        arr[start]*=-1;
        return rSide<arr.size() && canReach(arr, rSide) || lSide >=0 && canReach(arr, lSide);
        
    }

    // t-> O(n) s-> O(n)

    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0)
                return true;
            if(arr[curr]<0)
                continue;
            if(curr-arr[curr]>=0)
                q.push(curr-arr[curr]);
            if(curr+arr[curr]<arr.size())
                q.push(curr+arr[curr]);
            arr[curr]*=-1;
        }
        return false;
    }
};