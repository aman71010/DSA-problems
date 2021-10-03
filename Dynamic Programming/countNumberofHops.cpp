#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to count the number of ways in which frog can reach the top.


    //------------------ exponential -----------------------
    long long countWays(int n)
    {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        return countWays(n-1)+countWays(n-2)+countWays(n-3);
        
    }

    //------------------ t = O(n) s = O(n) -----------------------
    long long countWays(int n)
    {
        long long dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
        
    }

    //------------------ t = O(n) s = O(1) -----------------------
    long long countWays(int n)
    {
        long long dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3] + dp[(i-3)%3];
        }
        return dp[n%3];
        
    }
};