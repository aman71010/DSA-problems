#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    // recursion
    int longestCommonSubstring(string a, string b) {
        int n = a.length(), m = b.length();
        int res = 0;
        return lcs(a,b,n,m,res);
    }

    int lcs(string &a, string &b, int n, int m, int res){
        if(n==0 || m==0)
            return res;
        if(a[n-1]==b[m-1])
            res = lcs(a,b,n-1,m-1,res+1);
        else
            res = max(res, max(lcs(a,b,n-1,m,0), lcs(a,b,n,m-1,0)));
        return res;
    }

};

class Solution {
public:
    // T-> O(n*m) and S-> O(n*m) 
    int longestCommonSubstring(string a, string b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1];
        int res = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(dp[i][j], res);
                }
                else
                    dp[i][j] = 0;   
            }
        }
        return res;
    }
};