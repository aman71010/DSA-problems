#include<bits\stdc++.h>
using namespace std;

class Solution {
public:

    int findPivort(vector<int>& nums){
        int n = nums.size();
        int l = 0, h = n-1, m;
        while(l<h){
            m = l + (h-l)/2;
            if(m<h && nums[m]>nums[m+1])
                return m;
            else if(m>l && nums[m]<nums[m-1])
                return m-1;
            else if(nums[0]>nums[m])
                h = m-1;
            else
                l = m+1;
        }
        return l;
    }

    int binarySearch(vector<int>& nums, int target, int l, int h) {
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(nums[m]<target)
                l = m+1;
            else if(nums[m]>target)
                h = m-1;
            else
                return m;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        int p = findPivort(nums);
        if(nums[0] <= target && target <= nums[p])
            return binarySearch(nums, target, 0, p);
        else if(p!=n-1 && nums[p+1] <= target && target <= nums[n-1])
            return binarySearch(nums, target, p+1, n-1);
        else
            return -1;
    }
};