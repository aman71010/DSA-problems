#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.

    //recurrsive
    int eggDrop(int n, int k){
        if(k==0 || k==1)
            return k;
        if(n==1)
            return k;
        int res = INT_MAX, curr;
        for(int x=1; x<=k; x++){
            curr = max(eggDrop(n-1, k-1), eggDrop(n, k-x));
            res = min(res, curr);
        }
        return 1+res;
    }
};

class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.

    //bottom up
    int eggDrop(int n, int k){
        if(k==0 || k==1)
            return k;
        if(n==1)
            return k;
        int dp[n+1][k+1];
        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=2; j<=k; j++)
            dp[1][j] = j;
        for(int i=2; i<=n; i++){
            for(int j=2; j<=k; j++){
                dp[i][j] = INT_MAX;
                int curr = 0;
                for(int x=1; x<=j; x++){
                    curr = 1 + max(dp[i-1][x], dp[i][j-x-1]);
                    dp[i][j] = min(dp[i][j], curr);
                }
            }
        }
        return dp[n][k];
    }
};