#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    //recursive
    int maximumPath(int n, vector<vector<int>> mat){
        int ans = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            ans = max(ans, solve(mat, 0, i, sum, n));
        }
        return ans;
    }

    int solve(vector<vector<int>> &mat, int r, int c, int sum, int n){
        if(r<0 || r>=n || c>=n)
            return sum;
        sum += mat[r][c];
        int left = solve(mat, r+1, c-1, sum, n);
        int mid = solve(mat, r+1, c, sum, n);
        int right = solve(mat, r+1, c+1, sum, n);
        return max(left, max(mid, right));
    }
};

class Solution{
public:
    //dp 
    bool isValid(int r, int c, int n){
        return (c<0 || r>=n || c>=n);
    }

    int maximumPath(int n, vector<vector<int>> mat){
        int ans = 0;
        int next[3] = {-1, 0, 1};
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                int m = mat[i][j];
                for(int k=0; k<3; k++){
                    if(!isValid(i+1, j+next[k], n))
                        mat[i][j] = max(mat[i][j], m+mat[i+1][j+next[k]]);
                }
            }
        }
        for(int i=0; i<n; i++){
            ans = max(ans, mat[0][i]);
        }
        return ans;
    }
};
