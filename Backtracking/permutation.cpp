#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    void permutations(vector<int>& nums, int l, int r, vector<vector<int>>& res){
        if(l==r){
            res.push_back(nums);
            return;
        }
        else {
            for(int i=l; i<=r; i++){
                swap(nums[l], nums[i]);
                permutations(nums, l+1, r, res);
                swap(nums[l], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        permutations(nums, 0, n-1, res);
        return res;
    }
};