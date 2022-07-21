#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    void funcUtil(vector<int> nums, vector<int> &res, int start, int end){
        if(start<=end){
            int mid = start + (end-start)/2;
            res.push_back(nums[mid]);
            funcUtil(nums, res, start, mid-1);
            funcUtil(nums, res, mid+1, end);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> res;
        funcUtil(nums, res, 0, nums.size()-1);
        return res;
    }

};