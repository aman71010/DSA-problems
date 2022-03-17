#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n][m];
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0)
                    dp[i][j] = mat[i][j];
                else{
                    if(mat[i][j] == 1){
                        dp[i][j] = min(min(dp[i][j-1], dp[j][i-1]), dp[i-1][j-1]);
                        res = max(res, dp[i][j]);
                    }
                    else
                        dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
