#include<bits\stdc++.h>
using namespace std;

//recurrsion
class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        if(n==1){
            if(x>=1 && x<=m) return 1;
            else return 0;
        }
        long long ans = 0;
        for(int i=1; i<=m; i++){
            ans += noOfWays(m, n-1, x-i);
        }
        return ans;
    }
};

// top down
class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long>> dp(n+1, vector<long long> (x+1, -1));
        memoization(m, n, x, dp);
        return dp[n][x] == -1 ? 0: dp[n][x];
    }

    long long memoization(int m, int n, int x, vector<vector<long long>>& dp){
        if(x<0) return 0;
        if(dp[n][x]!=-1) return dp[n][x];
        if(n==1){
            if(x>=1 && x<=m) return dp[n][x] = 1;
            else return 0;
        }
        dp[n][x] = 0;
        for(int i=1; i<=m; i++){
            dp[n][x] += memoization(m, n-1, x-i, dp);
        }
        return dp[n][x];
    }
};

// bottom up T-> O(m*n*x) s-> O(n*x)
class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long>> dp(n+1, vector<long long> (x+1, 0));
        for(int j=1; j<=m && j<=x; j++)
            dp[1][j] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=x; j++){
                for(int k=1; k<=m && k<j; k++){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        return dp[n][x];
    }
};

// bottom up T-> O(n*x) s-> O(n*x)
class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long>> dp(n+1, vector<long long> (x+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=x; j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                if(j-m-1>=0)
                    dp[i][j] -= dp[i-1][j-m-1];
            }
        }
        return dp[n][x];
    }
};
