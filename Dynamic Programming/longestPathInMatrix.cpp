#include<bits\stdc++.h>
using namespace std;

// dfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dfs(mat, vis, i, j, 1, ans);
            }
        }
        return ans;
    }

    bool isSafe(vector<vector<bool>>& vis, int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j])
            return 1;
        return 0;
    }

    void dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis, int i, int j, int len, int& ans){
        vis[i][j] = 1;
        ans = max(ans, len);
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        for(int d=0; d<4; d++){
            int ni = i+dx[d], nj = j+dy[d];
            if(isSafe(vis, ni, nj, mat.size(), mat[0].size()) && mat[i][j] < mat[ni][nj])
                dfs(mat, vis, ni, nj, len+1, ans);
        }
        vis[i][j] = 0;
    }
};


// dfs + dp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        vector<vector<int>> dp(n, vector<int> (m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]!=0)
                    ans = max(ans, dp[i][j]);
                else
                    ans = max(ans, dfs(mat, vis, dp, i, j));
            }
        }
        return ans;
    }

    bool isSafe(vector<vector<bool>>& vis, int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j])
            return 1;
        return 0;
    }

    int dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis, vector<vector<int>>& dp, int i, int j){
        vis[i][j] = 1;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        int l = 0;
        for(int d=0; d<4; d++){
            int ni = i+dx[d], nj = j+dy[d];
            if(isSafe(vis, ni, nj, mat.size(), mat[0].size()) && mat[i][j] < mat[ni][nj]){
                if(dp[ni][nj] != 0)
                    l = max(l, dp[ni][nj]);
                else
                    l = max(l, dfs(mat, vis, dp, ni, nj));
            }
        }
        vis[i][j] = 0;
        dp[i][j] = l+1;
        return dp[i][j];
    }
};
