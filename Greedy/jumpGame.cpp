#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currLast = n-1;
        for(int i=n-1; i>=0; i--){
            if(nums[i]+i>=currLast)
                currLast = i;
        }
        return currLast==0 ? 1: 0;
    }
};