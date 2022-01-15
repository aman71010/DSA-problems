#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        if(mat.size()==0) return ans;
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, 0));
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int r = 0, c = 0, d = 0;
        for(int i=0; i<m*n; i++){
            ans.push_back(mat[r][c]);
            seen[r][c] = 1;
            int nr = r+dir[d][0], nc = c+dir[d][1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !seen[nr][nc]){
                r = nr;
                c = nc;
            }else {
                d = (d+1)%4;
                r = r+dir[d][0];
                c = c+dir[d][1];
            }
        }
        return ans;
    }
};