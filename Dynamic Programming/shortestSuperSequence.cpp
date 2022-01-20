#include<bits\stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    //recursive approach
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(X[m-1]==Y[n-1])
            return 1 + shortestCommonSupersequence(X,Y,m-1,n-1);
        return 1 + min(shortestCommonSupersequence(X,Y,m-1,n), shortestCommonSupersequence(X,Y,m,n-1));
    }
};

class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    //dp bottom up approach
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0)
                    dp[i][j] = j; 
                else if(j==0)
                    dp[i][j] = i;
                else if(X[i-1]==Y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    //dp bottom up approach
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        int lcs = longestCommonSubsequence(Y, X, n, m);
        return m+n-lcs;
    }

    int longestCommonSubsequence(string a, string b, int n, int m) {
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