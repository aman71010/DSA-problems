#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    //recursive
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = solve(n,x,y,z);
        return ans<0 ? 0: ans;
    }
    int solve(int n, int x, int y, int z)
    {
        if(n==0) 
            return 0;
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        if(x<=n)
            a = maximizeTheCuts(n-x, x, y, z);
        if(y<=n)
            b = maximizeTheCuts(n-y, x, y, z);
        if(z<=n)
            c = maximizeTheCuts(n-z, x, y, z);
        return max(a, max(b,c)) + 1;
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
        return dp[n]<0? 0: dp[n];
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
            dp[n] = max(a,max(b,c)) + 1;
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
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;
            if(x<=i)
                a = dp[i-x];
            if(y<=i)
                b = dp[i-y];
            if(z<=i)
                c = dp[i-z];
            dp[i] = max(a,max(b,c)) + 1;
        }
        return dp[n]<0? 0: dp[n];
    }
};