#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j])
                    q.push({i,j});
            }
        }
        if(q.size() == 0 || q.size() == n*n) 
            return -1;
        int ans = -1;
        while(!q.empty()){
            ans++;
            int s = q.size();
            int row[4] = {0,-1,0,1};
            int col[4] = {-1,0,1,0};
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int nr = i+row[k];
                    int nc = j+col[k];
                    if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc]==1)
                        continue;
                    grid[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};