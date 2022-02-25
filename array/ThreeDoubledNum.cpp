#include<bits\stdc++.h>
using namespace std;


int solve(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    unordered_map<int,int> freq, secFreq;
    for(int i=0; i<n; i++){
        if(nums[i]%4==0)
            ans += secFreq[nums[i]/2];
        if(nums[i]%2==0)
            secFreq[nums[i]] += freq[nums[i]/2];
        freq[nums[i]]++;
    }
    return ans;
}