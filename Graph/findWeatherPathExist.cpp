#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    if(dfs(grid, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
            return false;
        else if(grid[i][j]==2)
            return true;
        grid[i][j] = 0;
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        for(int d=0; d<4; d++)
            if(dfs(grid, i+x[d], j+y[d]))
                return true;
        return false;
    }
};