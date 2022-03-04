#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(board, word, i, j, m, n))
                    return true;
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='#')
            return false;
        return true;
    }


    bool dfs(vector<vector<char>>& board, string word, int i, int j, int m, int n){
        if(word[0]!=board[i][j])
            return false;
        if(word.length()==1)
            return true;
        char c = board[i][j];
        board[i][j] = '#';
        int x[4] = {0,-1,0,1};
        int y[4] = {-1,0,1,0};
        for(int d=0; d<4; d++){
            if(isSafe(board, i+x[d], j+y[d], m, n) && dfs(board, word.substr(1), i+x[d], j+y[d], m, n))
                return true;
        }
        board[i][j] = c;
        return false;
    }
    
};