#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    //recurrsive
    long long int optimalKeys(int n){
        if(n<=6)
            return n;
        long long int ans = 0;
        for(int bp = n-3; bp<=1; bp--){
            long long int curr = (n-bp-1)*optimalKeys(bp);
            if(curr>ans)
                curr = ans;
        }
        return ans;
    }
};

class Solution{
public:
    //bottom up
    long long int optimalKeys(int n){
        if(n<=6)
            return n;
        long long int dp[n+1];
        for(int i=0; i<=6; i++)
            dp[i] = i;
        for(int i=7; i<=n; i++){
            dp[i] = 0;
            for(int j=i-3; j>=1; j--){
                long long int curr = (i-j-1)*dp[j];
                if(curr>dp[i])
                    dp[i] = curr;
            }
        }
        return dp[n];
    }
};