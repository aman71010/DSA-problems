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

};