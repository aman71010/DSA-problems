#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // naive solution
    int longestPalindromeSubseq(string s) {
        return LPS(s, 0, s.length()-1);
    }
    int LPS(string &s, int l, int h){
        if(l==h)
            return 1;
        if(l+1==h && s[l]==s[h])
            return 2;
        if(s[l]==s[h])
            return LPS(s, l+1, h-1)+2;
        return max(LPS(s, l, h-1), LPS(s, l+1, h));
    }

    // T-> O(n^2) and S-> O(n^2)
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int g=0; g<n; g++){
            for(int i=0,j=g; j<n; i++, j++){
                if(g==0)
                    dp[i][j] = 1;
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else{
                    if(s[i]==s[j])
                        dp[i][j] = 2 + dp[i+1][j-1];
                    else
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};