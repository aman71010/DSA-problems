#include<bits\stdc++.h>
using namespace std;


class Solution {
public:
    //-----------------T->O(m*n) and S->O(m*n)-------------------------------
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<int> v = {0, 1, 0, -1, 0};
        for(int i=0; i<m; i++ ){
            for(int j=0; j<n; j++ ){
                if(mat[i][j]==0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+v[i], nc=c+v[i+1];
                if(nr<0 || nc<0 || nr>=m || nc>n || mat[nr][nc]!=-1)
                    continue;
                mat[nr][nc] = mat[r][c]+1;
                q.push({nr, nc});
            }   
        }
        return mat;
    }

    //-----------------T->O(m*n) and S->O(1)-------------------------------
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxDis = m+n, top, right, bottom, left;
        for(int i=0; i<m; i++ ){
            for(int j=0; j<n; j++ ){
                if(mat[i][j]==0)
                    continue;
                top = left = maxDis;
                if(i-1>=0) top = mat[i-1][j];
                if(j-1>=0) left = mat[i][j-1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        for(int i=m-1; i>=0; i-- ){
            for(int j=n-1; j>=0; j-- ){
                if(mat[i][j]==0)
                    continue;
                bottom = right = maxDis;
                if(i+1<m) bottom = mat[i+1][j];
                if(j+1<n) right = mat[i][j+1];
                mat[i][j] = min(mat[i][j],  min(bottom, right) + 1);
            }
        }
        return mat;
    }
};