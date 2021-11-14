#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    for(auto v: blocked_cells)
            if((v[0]==1 && v[1]==1) || (v[0]==n && v[1]==m))
                return 0;
        vector<vector<int>> mat(n, vector<int> (m, 0));
        for(auto v: blocked_cells)
            mat[v[0]-1][v[1]-1] = -1;
        for(int i=0; i<n; i++){
            if(mat[i][0]==0)
                mat[i][0] = 1;
            else
                break;
        }
        for(int i=1; i<m; i++){
            if(mat[0][i]==0)
                mat[0][i] = 1;
            else
                break;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
              if(mat[i][j] == -1) continue;
              if(mat[i-1][j]>0){
                  mat[i][j] = (mat[i-1][j]+mat[i][j])%1000000007;
              }
              if(mat[i][j-1]>0){
                  mat[i][j] = (mat[i][j-1]+mat[i][j])%1000000007;
              }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return mat[n-1][m-1];
	}
};