#include<bits/stdc++.h>
using namespace std;


// --------------------------------------- top down approach --------------------------------------
class Solution {
public:
    int solve(vector<vector<vector<int>>> &dp, vector<pair<int, int>>& arr, int m, int n, int N){
        if(N==0 || m+n==0)
            return 0;
        if(dp[m][n][N] != -1)
            return dp[m][n][N];
        if(m-arr[N-1].first >= 0 && n-arr[N-1].second >= 0)
            dp[m][n][N] = 1+solve(dp, arr, m-arr[N-1].first, n-arr[N-1].second, N-1);
        dp[m][n][N] = max(dp[m][n][N], solve(dp, arr, m, n, N-1));
        return dp[m][n][N];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr;
        for(string s: strs){
            int zeros = 0, ones = 0;
            for(char c: s){
                if(c == '1') ones++;
                else zeros++;
            }
            arr.push_back({zeros, ones});
        }
        int N = strs.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (N+1, -1)));
        return solve(dp, arr, m, n, N);
    }
};

// ---------------------------------------- bottom up approach --------------------------------------
// T->O(N*m*n) and s->O(m*n)
class Solution {
public:
    
    pair<int, int> getCount(string &str){
        int zeros = 0, ones = 0;
        for(char c: str){
            if(c=='0')
                zeros++;
            else
                ones++;
        }
        return {zeros, ones};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(string s: strs){
            pair<int, int> pr = getCount(s);
            int zeros = pr.first;
            int ones = pr.second;
            for(int i=m; i>=zeros; i--)
                for(int j=n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], 1+dp[i-zeros][j-ones]);
        }
        return dp[m][n];
    }
};