#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //--------------T = exponentail----------------------
    int minCoins(int coins[], int m, int N)
    {
        if(N == 0)
            return 0;
        int res = INT_MAX;
        for(int i=0; i<m; i++){
            if(coins[i]<=N){
                int subRes = minCoins(coins, m, N-coins[i]);
                if(subRes!=INT_MAX && subRes+1<res)
                    res = subRes+1;
            }
        }
        return res;
    }

    //---------------------T = O(N*m) and S=O(N)-------------

    int minCoins(int coins[], int m, int N)
    {
        int dp[N+1];
        dp[0] = 0;
        for(int i=1; i<=N; i++)
            dp[i] = INT_MAX;
        for(int i=1; i<=N; i++){
            for(int j=0; j<m; j++){
                if(coins[j]<=i){
                    int subRes = dp[i-coins[j]];
                    if(subRes!=INT_MAX && subRes+1<dp[i])
                        dp[i] = subRes+1;
                }
            }
        }

        if(dp[N] == INT_MAX)
            return -1;
        return dp[N];
    }

    
    
};