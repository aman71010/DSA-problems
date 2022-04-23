#include<bits\stdc++.h>
using namespace std;

// naive recurrsive
class Solution{
	public:
	int minOperations(string str1, string str2) { 
	    return solve(str1, str2, str1.length(), str2.length());
	} 

    int solve(string s1, string s2, int n, int m){
        if(n==0) return m;
        if(m==0) return n;
        if(s1[n-1] == s2[m-1])
            return solve(s1, s2, n-1, m-1);
        return 1 + min(solve(s1, s2, n-1, m), solve(s1, s2, n, m-1));
    }
};

// bottom up dp approach
class Solution{
	public:
	int minOperations(string str1, string str2) { 
        int n = str1.length(), m = str2.length();
        if(n == 0) return m;
        if(m == 0) return n;
        int dp[n+1][m+1] = {0};
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else{
                    if(str1[i-1] == str2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};