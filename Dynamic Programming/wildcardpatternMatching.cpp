#include<bits\stdc++.h>
using namespace std;


//recursive
class Solution{
  public:
    int wildCard(string pattern,string str){
        int m = pattern.length(), n = str.length();
        if(m==0 && n==0)
            return 1;
        string pat = "";
        pat += pattern[0];
        for(int i=1; i<m; i++){
            if(pattern[i] == '*' && pattern[i] == pattern[i-1])
                continue;
            else
                pat += pattern[i];
        }
        m = pat.length();
        return solve(pat, str, m, n);
    }

    bool solve(string &pat, string &str, int m, int n){
        if(m==0 && n==0)
            return 1;
        if(m==0)
            return 0;
        if(n==0){
            if(m==1 && pat[m-1] == '*')
                return 1;
            else
                return 0;
        }
        if(pat[m-1] == '?' || pat[m-1] == str[n-1])
            return solve(pat, str, m-1, n-1);
        if(pat[m-1] == '*'){
            return solve(pat, str, m-1, n) || solve(pat, str, m, n-1);
        }
        return 0; // if( pat[m-1] and str[n-1] are alphabet char but not same.)
    }
};


// top down
class Solution{
  public:
    int wildCard(string pattern,string str)
    {
        int m = pattern.length(), n = str.length();
        if(m==0 && n==0)
            return 1;
        string pat = "";
        pat += pattern[0];
        for(int i=1; i<m; i++){
            if(pattern[i]==pattern[i-1] && pattern[i]=='*')
                continue;
            else
                pat += pattern[i];
        }
        m = pat.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return dp[m][n] = solve(pat, str, m, n, dp);
    }

    int solve(string pat, string str, int m, int n, vector<vector<int>> &dp){
        if(dp[m][n] != -1)
            return dp[m][n];
        if(m==0 && n==0)
            return dp[m][n] = 1;
        if(m==0)
            return dp[m][n] = 0;
        if(n==0){
            if(m==1 && pat[m-1]=='*')
                return dp[m][n] = 1;
            else
                return dp[m][n] = 0;
        }
        if(pat[m-1]=='?' || pat[m-1]==str[n-1])
            return dp[m][n] = solve(pat, str, m-1, n-1, dp);
        if(pat[m-1]=='*')
            return dp[m][n] = solve(pat, str, m-1, n, dp) || solve(pat, str, m, n-1, dp);
        return dp[m][n] = 0;
    }
};

// bottom up
class Solution{
    public:
    int wildCard(string pattern,string str)
    {
        int m = pattern.length(), n = str.length();
        if(m==0 && n==0)
            return 1;
        string pat = "";
        pat += pattern[0];
        for(int i=1; i<m; i++){
            if(pattern[i]==pattern[i-1] && pattern[i]=='*')
                continue;
            else
                pat += pattern[i];
        }
        m = pat.length();
        int dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        if(pat[0] == '*')
            dp[1][0] = true;
        for(int i=2; i<=m; i++)
            dp[i][0] = false;
        for(int j=1; j<=n; j++)
            dp[0][j] = 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(pat[i-1]=='?' || pat[i-1]==str[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(pat[i-1]=='*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};