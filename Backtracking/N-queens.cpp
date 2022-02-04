#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        int k = 2*n-1;
        vector<bool> curRow(n, 0);
        vector<bool> upLeft(k, 0);
        vector<bool> botLeft(k, 0);
        solve(res, temp, curRow, upLeft, botLeft, 0, n);
        return res;
    }

    void solve(vector<vector<int>> &res, vector<int> &temp, vector<bool> &curRow, vector<bool> &upLeft, vector<bool> &botLeft, int col, int n){
        if(col>=n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(curRow, upLeft, botLeft, i, col, n)){
                temp.push_back(i+1);
                curRow[i] = true;
                upLeft[i-col+n-1] = true;
                botLeft[i+col] = true;
                solve(res, temp, curRow, upLeft, botLeft, col+1, n);
                temp.pop_back();
                curRow[i] = false;
                upLeft[i-col+n-1] = false;
                botLeft[i+col] = false;
            }
        }
    } 

    bool isSafe(vector<bool> &curRow, vector<bool> &upLeft, vector<bool> &botLeft, int i, int col, int n){
        if(curRow[i])
            return false;
        if(upLeft[i-col+n-1])
            return false;
        if(botLeft[i+col])
            return false;
        return true;
    }
};