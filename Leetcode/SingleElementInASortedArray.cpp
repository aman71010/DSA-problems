#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //T = O(logn) S = O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1, m;
        while(l<h){
            m = l + (h-l)/2;
            if(nums[m] == nums[m+1]){
                if((m-l)%2==0) l = m+2;
                else h = m-1;
            }
            else if(nums[m] == nums[m-1]){
                if((m-l)%2==0) h = m-2;
                else l = m + 1;
            }
            else return nums[m];
        }
        return nums[l];
    }
};