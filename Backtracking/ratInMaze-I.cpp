#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
            return {};
        vector<vector<bool>> visited(n, vector<bool> (n, 0)); 
        vector<string> res;
        string s = "";
        getPath(m, visited, res, s, 0, 0, n);
        return res;
    }

    bool isValid(int i, int j, int n, vector<vector<int>> &m, vector<vector<bool>> &visited){
        return (i>=0 && i<n && j>=0 && j<n && m[i][j]!= 0 && !visited[i][j]);
    }

    void getPath(vector<vector<int>> &m, vector<vector<bool>> &visited, vector<string> &res, string s, int i, int j, int n){
        if(i==n-1 && j==n-1){
            res.push_back(s);
            return;
        }
        visited[i][j] = 1;
        string dir[4] = {"L","U","R","D"};
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        for(int k=0; k<4; k++){
            if(isValid(i+x[k], j+y[k], n, m, visited)){
                getPath(m, visited, res, s+dir[k], i+x[k], j+y[k], n);
            }
        }
        visited[i][j] = 0;
    }
};