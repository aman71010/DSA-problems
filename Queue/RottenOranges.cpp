#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int total = 0, cnt = 0, days = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()) days++;
        }
        return total==cnt ? days: -1;
    }
};

int main(){
    return 0;
}