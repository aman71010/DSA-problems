#include<bits\stdc++.h>
using namespace std;


class Solution {
public:
    //-----------------T->O(m*n) and S->O(m*n)-------------------------------
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0, ans = -1;
        queue<pair<int, int>> q;
        vector<int> v = {0, 1, 0, -1, 0};
        for(int i=0; i<m; i++ ){
            for(int j=0; j<n; j++ ){
                if(grid[i][j]==2)
                    q.push({i, j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> p = q.front();
                int r=p.first, c=p.second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr=r+v[i], nc=c+v[i+1];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }   
            }
            ans++;
        }
        if(fresh!=0)
            return -1;
        else if(ans==-1)
            return 0;
        else
            return ans;
    }
    
};