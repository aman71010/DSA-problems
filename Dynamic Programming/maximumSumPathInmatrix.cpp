#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    //recursive
    int maximumPath(int n, vector<vector<int>> mat){
        int ans = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            ans = max(ans, solve(mat, 0, i, n));
        }
        return ans;
    }

    bool isValid(int n, int r, int c){
        return (r>=0 && r<n && c>=0 && c<n);
    }

    int solve(vector<vector<int>> &mat, int r, int c, int n){
        if(r==n-1)
            return mat[r][c];
        int ma = -1;
        if(isValid(n, r+1, c-1))
            ma = max(ma, solve(mat, r+1, c-1, n));
        if(isValid(n, r+1, c))
            ma = max(ma, solve(mat, r+1, c, n));
        if(isValid(n, r+1, c+1))
            ma = max(ma, solve(mat, r+1, c+1, n));
        return mat[r][c]+ma;
    }
};

class Solution{
public:
    //dp 
    bool isValid(int n, int r, int c){
        return (r>=0 && r<n && c>=0 && c<n);
    }

    int maximumPath(int n, vector<vector<int>> mat){
        int ans = 0;
        int next[3] = {-1, 0, 1};
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int ma = -1;
                for(int k=0; k<3; k++)
                    if(isValid(n, i+1, j+next[k]))
                        ma = max(ma, mat[i+1][j+next[k]]);
                mat[i][j] += ma;
            }
        }
        for(int i=0; i<n; i++){
            ans = max(ans, mat[0][i]);
        }
        return ans;
    }
};
