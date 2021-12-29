#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    // T-> O(n*n) and S-> O(n*n) 
    int longestCommonSubsequence(string a, string b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(a[i-1]==b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);   
            }
        }
        return dp[n][m];
    }

};