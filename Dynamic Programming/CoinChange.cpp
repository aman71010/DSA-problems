#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //--------------T = exponentail----------------------
    int countWays(int coins[], int m, int N)
    {
        
    }

    //---------------------T = O(N*m) and S=O(N)-------------

    int countWays(int coins[], int m, int N)
    {
        int dp[N+1] = {0};
        dp[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=coins[i]; j<=N; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[N];
    }

    
    
};