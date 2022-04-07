#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) S-> O(1) Naive

// T-> O(n) S-> O(n)
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(arr[i]==0)
                sum += -1;
            else
                sum += arr[i];
            mp[sum]++;
        }
        long long int ans = 0;
        for(auto x: mp){
            if(x.second > 1)
                ans += (x.second*(x.second-1))/2;
        }
        ans += mp[0];
        return ans;
    }
};