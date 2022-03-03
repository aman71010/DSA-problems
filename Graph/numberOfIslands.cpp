#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1')
            return;
        grid[i][j] = '2';
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        for(int d=0; d<4; d++)
            dfs(grid, i+x[d], j+y[d]);
    }
};