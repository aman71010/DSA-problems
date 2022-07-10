#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    //recursive
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3] = {x, y, z};
        int ans = solve(n, arr);
        return ans == INT_MIN ? 0: ans;
    }

    int solve(int n, int arr[])
    {
        if(n==0) 
            return 0;
        int res = INT_MIN;
        for(int i=0; i<3; i++){
            if(arr[i]<=n){
                int subRes = solve(n-arr[i], arr);
                if(subRes != INT_MIN && res < subRes+1)
                    res = subRes+1;
            }
        }
        return res;
    }
};

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    //dp top down
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0] = 0;
        for(int i=1; i<=n; i++)
            dp[i] = -1;
        solve(n,x,y,z,dp);
        return dp[n]==INT_MIN? 0: dp[n];
    }

    int solve(int n, int x, int y, int z, int dp[]){
        if(n==0) 
            return dp[0];
        if(dp[n]==-1){
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;
            if(x<=n)
                a = solve(n-x, x, y, z, dp);
            if(y<=n)
                b = solve(n-y, x, y, z, dp);
            if(z<=n)
                c = solve(n-z, x, y, z, dp);
            int subRes = max(a,max(b,c));
            dp[n] = (subRes == INT_MIN) ? subRes: subRes+1;
        }
        return dp[n];
    }
};

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    //dp bottom up
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i]=  INT_MIN;
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;
            if(x<=i)
                a = dp[i-x];
            if(y<=i)
                b = dp[i-y];
            if(z<=i)
                c = dp[i-z];
            int subRes = max(a,max(b,c));
            dp[i] = (subRes == INT_MIN) ? subRes: subRes+1;
        }
        return dp[n]==INT_MIN? 0: dp[n];
    }
};