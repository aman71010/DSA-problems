#include<bits\stdc++.h>
using namespace std;


class Solution {
    public:

    struct cell {
        int x, y, dis;
        cell(){}
        cell(int x, int y, int dis){
            this->x = x;
            this->y = y;
            this->dis = dis;
        }
    };

    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n){
        int ki = n-KnightPos[0], kj = KnightPos[1]-1; // convert to 0-based index
        int ti = n-TargetPos[0], tj = TargetPos[1]-1; // convert to 0-based index
	    vector<vector<bool>> visited(n, vector<bool>(n, 0));
        cell t;
        t.x = ki, t.y = kj, t.dis = 0;
        queue<cell> q;
        q.push(t);
        visited[t.x][t.y] = 1;
        while(!q.empty()){
            cell curr = q.front();
            q.pop();
            if(curr.x == ti && curr.y == tj)
                return curr.dis;
            int x[8] = {-1,-2,-2,-1,1,2,2,1};
            int y[8] = {-2,-1,1,2,2,1,-1,-2};
            for(int d=0; d<8; d++){
                int nx = curr.x + x[d], ny = curr.y + y[d];
                if(isSafe(visited, nx, ny, n)){
                    t.x = nx, t.y = ny, t.dis = curr.dis+1;
                    q.push(t);
                    visited[t.x][t.y] = 1;
                }
            }
        }
	}

    bool isSafe(vector<vector<bool>>& visited, int i, int j, int n){
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j]==1)
            return false;
        return true;
    }
};
    