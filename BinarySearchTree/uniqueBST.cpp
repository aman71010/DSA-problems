#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //Function to return the total number of possible unique BST. 
    int numTrees(long long n) {
        long long dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                long long subRes = (dp[i-j]*dp[j-1])%1000000007;
                dp[i] = (dp[i] + subRes)%1000000007;
            }
        }
        return (int)dp[n];
    }
};