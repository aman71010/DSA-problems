#include<bits\stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pip;

class Solution{
    public:

    bool isSafe(int i, int j, int n){
        if(i<0 || i>=n || j<0 || j>=n)
            return false;
        return true;
    }

    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n, vector<int> (n, INT_MAX));
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        minHeap.push({grid[0][0],{0,0}});
        while(!minHeap.empty()){
            pip curr = minHeap.top();
            minHeap.pop();
            int r = curr.second.first, c = curr.second.second;
            int currCost = curr.first;
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            for(int d=0; d<4; d++){
                int nr =  r + dx[d], nc = c + dy[d];
                if(isSafe(nr, nc, n) && mat[nr][nc] > grid[nr][nc]+currCost){
                    mat[nr][nc] = grid[nr][nc]+currCost;
                    minHeap.push({mat[nr][nc],{nr,nc}});
                }
            }
        }
        return mat[n-1][n-1];
    }
};
