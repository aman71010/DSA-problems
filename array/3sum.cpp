#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T-> O(n*2) and S-> O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int num = nums[i]==0 ? 0: nums[i]*(-1);
            int l = i+1, h = n-1;
            while(l<h){
                if(nums[l]+nums[h] < num)
                    l++;
                else if(nums[l]+nums[h] > num)
                    h--;
                else{
                    res.push_back({nums[i], nums[l], nums[h]});
                    while(l<h && nums[l]==nums[l+1])
                        l++;
                    while(l<h && nums[h]==nums[h-1])
                        h--;
                    l++;
                    h--;
                }
            }   
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};