#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool validRow(vector<vector<int>> &mat, int r){
        unordered_set<int> s;
        for(int i=0; i<9; i++){
            if(s.find(mat[r][i])!=s.end())
                return false;
            if(mat[r][i]!=0)
                s.insert(mat[r][i]);
        }
        return true;
    }

    bool validColumn(vector<vector<int>> &mat, int c){
        unordered_set<int> s;
        for(int i=0; i<9; i++){
            if(s.find(mat[i][c])!=s.end())
                return false;
            if(mat[i][c]!=0)
                s.insert(mat[i][c]);
        }
        return true;
    }

    bool valid3Box(vector<vector<int>> &mat, int startRow, int startCol){
        unordered_set<int> s;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(s.find(mat[startRow + i][startCol + j])!=s.end())
                    return false;
                if(mat[startRow + i][startCol + j]!=0)
                    s.insert(mat[startRow + i][startCol + j]);
            }
        }
        return true;
    }

    bool isValidConfig(vector<vector<int>> &mat, int r, int c){
        return validRow(mat, r) && validColumn(mat, c) && valid3Box(mat, r, c);
    }

    int isValid(vector<vector<int>> mat){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(!isValidConfig(mat, i, j))
                    return 0;
            }
        }
        return 1;
    }

};

int main(){
    return 0;
}