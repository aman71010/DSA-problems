#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    //recursion
    int minimumJumps(int arr[], int n){
        if(n != 1 && arr[0] == 0)
            return -1;
        int res = minJumps(arr, n);
        return res==INT_MAX? -1: res;
    }

    int minJumps(int arr[], int n){
        if(n==1)
            return 0;
        int res = INT_MAX;
        for(int i=n-2; i>=0; i--){
            if(i+arr[i]>=n-1){
                int subRes = minJumps(arr,i+1);
                if(subRes != INT_MAX && res > subRes+1)
                    res = subRes+1;
            }
        }
        return res;
    }
};

class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    //using dp
    int minimumJumps(int arr[], int n){
        if(n != 1 && arr[0] == 0)
            return -1;
        int dp[n];
        dp[0] = 0;
        for(int i=1; i<n; i++){
            dp[i] = INT_MAX;
            for(int j=0; j<i; j++){
                if(j+arr[j]>=i && dp[j] != INT_MAX ){
                    if(dp[i]>dp[j]+1){
                        dp[i] = dp[j]+1;
                        break;
                    } 
                }
            }
        }
        return dp[n-1]==INT_MAX? -1: dp[n-1];
    }
};

class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    //linear time
    int minimumJumps(int arr[], int n){
        if(n==1)
            return 0;
        if(arr[0] == 0)
            return -1;
        int maxReach = arr[0];
        int step = arr[0];
        int jumps = 1; 
        for(int i=1; i<n; i++){
            if(i==n-1) return jumps;
            maxReach = max(maxReach, arr[i]+i);
            step--;
            if(step==0){
                jumps++;
                if(i>=maxReach)
                    return -1;
                step = maxReach-i;
            }
        }
        return -1;
    }
};