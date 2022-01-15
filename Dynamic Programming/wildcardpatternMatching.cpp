#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    int wildCard(string pattern,string str)
    {
        int n1 = pattern.length(), m = str.length();
        string pat = "";
        pat += pattern[0];
        for(int i=1; i<n1; i++){
            if(pattern[i]==pattern[i-1] && pattern[i]=='*')
                continue;
            else
                pat += pattern[i];
        }
        int n = pat.length();
        int dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            if(pat[i-1]=='*')
                dp[0][i] = dp[0][i-1];
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(pat[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else if(pat[j-1]=='?' || pat[j-1]==str[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};