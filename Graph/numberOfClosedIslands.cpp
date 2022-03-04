#include<bits\stdc++.h>
using namespace std;

class Solution {
public:

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[i][0]==0)
                dfs(grid, i, 0);
        }
        for(int i=0; i<m; i++){
            if(grid[i][n-1]==0)
                dfs(grid, i, n-1);
        }
        for(int j=0; j<n; j++){
            if(grid[0][j]==0)
                dfs(grid, 0, j);
        }
        for(int j=0; j<n; j++){
            if(grid[m-1][j]==0)
                dfs(grid, m-1, j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=0)
            return;
        grid[i][j] = -1;
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        for(int d=0; d<4; d++)
            dfs(grid, i+x[d], j+y[d]);
    }
};