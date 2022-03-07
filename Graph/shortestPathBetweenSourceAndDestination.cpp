#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:

    struct cell{
        int x, y, dis;
        cell() {};
        cell(int x, int y, int dis){
            this->x = x;
            this->y = y;
            this->dis = dis;
        }
    };

    // BFS
    int shortestDistance(int n, int m, vector<vector<int>> grid, int x, int y) {
        if(grid[0][0] == 0 || grid[x][y] == 0)
            return -1;
        cell t;
        t.x = 0, t.y = 0, t.dis = 0;
        grid[t.x][t.y] = 0;
        queue<cell> q;
        q.push(t);
        while(!q.empty()){
            cell curr = q.front();
            q.pop();
            if(curr.x == x && curr.y == y)
                return curr.dis;
            int r[4] = {0,-1,0,1};
            int c[4] = {-1,0,1,0};
            for(int d=0; d<4; d++){
                int nx = curr.x + r[d], ny = curr.y + c[d];
                if(isSafe(grid, nx, ny)){
                    t.x = nx, t.y = ny, t.dis = curr.dis + 1;
                    q.push(t);
                    grid[nx][ny] = 0;
                }
            }
        }
        return -1;
    }

    bool isSafe(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
            return false;
        return true;
    }
};
