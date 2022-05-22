#include<bits\stdc++.h>
using namespace std;

// T-> O(n) s-> O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp;
        for(int i: nums)
            mp[i] = false;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!mp[nums[i]]){
                int curr = nums[i];
                mp[curr] = true;
                int left = 0;
                while(mp.find(curr-1)!=mp.end()){
                    left++;
                    mp[curr-1] = true;
                    curr--;
                }
                curr = nums[i];
                int right = 0;
                while(mp.find(curr+1)!=mp.end()){
                    right++;
                    mp[curr+1] = true;
                    curr++;
                }
                ans = max(ans, left+1+right);
            }
        }
        return ans;
    }
};

// T-> O(n) s-> O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i: nums)
            st.insert(i);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(st.find(nums[i]-1)==st.end()){
                int curr = nums[i];
                while(st.find(curr)!=st.end())
                    curr++;
                ans = max(ans, curr-nums[i]);
            }
        }
        return ans;
    }
};