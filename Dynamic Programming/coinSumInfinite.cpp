#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(amount, coins, n-1);
    }

    int solve(int amount, vector<int>& coins, int i){
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0;
        if(amount > 0 && i<0)
            return 0;
        return solve(amount-coins[i], coins, i) + solve(amount, coins, i-1);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i == 0)
                    dp[i][j] = 0;
                else if(j == 0)
                    dp[i][j] = 1;
                else{
                    if(coins[i-1]<=j)
                        dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};