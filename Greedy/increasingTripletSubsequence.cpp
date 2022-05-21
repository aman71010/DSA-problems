#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) s-> O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    temp[i] = max(temp[i], temp[j]+1);
                if(temp[i]==2) return true;
            }
        }
        return false;
    }
};

// T-> O(n) s-> O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = -1;
        int mi = 0;
        for(int i=1; i<n; i++){
            if(nums[mi]<nums[i])
                left[i] = mi;
            else{
                left[i] = -1;
                mi = i;
            }
        }
        vector<int> right(n);
        right[n-1] = -1;
        int ma = n-1;
        for(int i=n-2; i>=0; i--){
            if(nums[ma]>nums[i])
                right[i] = ma;
            else{
                right[i] = -1;
                ma = i;
            }
        }
        for(int i=1; i<n-1; i++){
            if(left[i]!=-1 && right[i]!=-1)
                return true;
        }
        return false;
    }
};

// T-> O(n) s-> O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minNum = nums[0];
        int strJ = INT_MAX;
        int strI = minNum;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==minNum) continue;
            else if(nums[i]<minNum){
                minNum = nums[i];
                continue;
            }
            else if(nums[i]<strJ){
                strJ = nums[i];
                strI = minNum;
            }
            else if(nums[i]>strJ){
                return true;
            }
        }
        return false;
    }
};