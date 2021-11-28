#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //---------------------------------------------------RECURSIVE--------------------------------------------------------------
    //exponntial t-> O(n^3)
    int solveEditDistance(string &s, string &t, int m, int n){
        if(m==0) return n;
        if(n==0) return m;
        if(s[m-1]==t[n-1])
            return solveEditDistance(s, t, m-1, n-1);
        return 1+min(solveEditDistance(s, t, m, n-1), min(solveEditDistance(s, t, m-1, n), solveEditDistance(s, t, m-1, n-1)));
    }

    int editDistance(string s, string t) {
        return solveEditDistance(s, t, s.length(), t.length());
    }
    
    //---------------------------------------------------DP(TABULATION)--------------------------------------------------------------
    // t-> O(m*n) s-> O(m*n)
    int editDistance(string s, string t) {
        int m = s.length(), n = t.length();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0) 
                    dp[i][j] = j;
                else if(j==0) 
                    dp[i][j] = i;
                else if(s[j-1]==t[i-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }

    //---------------------------------------------------DP(TABULATION)--------------------------------------------------------------
    // t-> O(m*n) s-> O(m)
    int editDistance(string s, string t) {
        int m = s.length(), n = t.length();
        int dp[2][m+1];
        for(int j=0; j<=m; j++)
            dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(j==0) 
                    dp[i%2][j] = i;
                else if(s[j-1]==t[i-1]) 
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                else
                    dp[i%2][j] = 1 + min(min(dp[i%2][j-1], dp[(i-1)%2][j]), dp[(i-1)%2][j-1]);
            }
        }
        return dp[n%2][m];
    }
};