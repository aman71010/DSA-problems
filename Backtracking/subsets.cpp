#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    // T->O(n*(n^2)) S-> O(2^n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int setSize = nums.size();
        int totalSubsets = pow(2, setSize);
        for(int i=0; i<totalSubsets; i++){
            vector<int> subset;
            for(int j=0; j<setSize; j++){
                if(i & (1<<j))
                    subset.push_back(nums[j]);
            }
            res.push_back(subset);
        } 
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subSet;
        int setSize = nums.size();
        getSubsets(nums, res, subSet, 0);
        return res;
    }
    void getSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &subSet, int i){
        res.push_back(subSet);
        for(int j=i; j<nums.size(); j++){
            subSet.push_back(nums[j]);
            getSubsets(nums, res, subSet, i+1);
            subSet.pop_back();
        }
        return;
    }
};