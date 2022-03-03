#include<bits\stdc++.h>
using namespace std;

class Solution {
    public:
    int findMaxArea(vector<vector<int>>& grid) {
        int ans = 0, sum;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    sum = 0;
                    dfs(grid, i, j, sum);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &sum){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
            return;
        sum++;
        grid[i][j] = 2;
        int x[8] = {0,-1,0,1,-1,-1,1,1};
        int y[8] = {-1,0,1,0,-1,1,-1,1};
        for(int d=0; d<8; d++)
            dfs(grid, i+x[d], j+y[d], sum);
    }
};