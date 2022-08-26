#include<bits\stdc++.h>
using namespace std;

//recurrsive
class Solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        if(n<=0) return 0;
        if(wt[n-1]>W)
            return knapSack(W, wt, val, n-1);
        return max(knapSack(W-wt[n-1], wt, val, n-1)+val[n-1], knapSack(W, wt, val, n-1));
    }
};

// bottom up
class Solution{
    public:
    int knapSack(int W, int wt[], int val[], int N) { 
        int dp[N+1][W+1];
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else{
                    if(wt[i-1]>j)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
                }
            }
        }
        return dp[N][W];
    }
};