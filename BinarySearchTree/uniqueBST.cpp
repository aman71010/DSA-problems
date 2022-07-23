#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //Function to return the total number of possible unique BST. 
    // T-> O(N^2) S-> O(N)
    int numTrees(long long n) {
        int mod = 1e9+7;
        long long dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                long long subRes = (dp[i-j]*dp[j-1])%mod;
                dp[i] = (dp[i] + subRes)%mod;
            }
        }
        return (int)dp[n];
    }
};


class Solution 
{
    public:
    // T-> O(N) S-> O(1)
    int numTrees(long long n){
        unsigned long bc = binomialCoeff(2*n, n);
        return (int)(bc/(n+1));
    }

    unsigned long binomialCoeff(int n, int k){
        if(n-k < k)
            k = n-k;
        unsigned long res = 1;
        for(int i=0; i<k; i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
};