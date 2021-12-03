#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //---------------------------------------------------RECURSIVE--------------------------------------------------------------
    //exponntial t-> O(n^2)
    int solve(vector<int>& nums, int i){
        if(i>=nums.size())
            return 0;
        return max(solve(nums, i+1), nums[i]+solve(nums, i+2));
    }

    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }

    //---------------------------------------------------DP(MEMOIZATION)--------------------------------------------------------------
    // t-> O(n) s-> O(n)

    int solveMem(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = max(solveMem(nums, i+1, dp), nums[i]+solveMem(nums, i+2, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solveMem(nums, 0, dp);
    }

    //---------------------------------------------------DP(TABULATION)--------------------------------------------------------------
    // t-> O(n) s-> O(n)

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, 0);
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }

    //---------------------------------------------------DP(TABULATION)--------------------------------------------------------------
    // t-> O(n) s-> O(1)

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev = 0, prev2 = 0, curr = 0;
        for(int i=0; i<n; i++){
            curr = max(prev, nums[i]+prev2);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};