#include<bits\stdc++.h>
using namespace std;

class Solution{
public:

    bool validBox(vector<vector<int>> &mat, int startRow, int startCol){
        int box[9] = {0};
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(mat[i+startRow][j+startCol]){
                    if(box[mat[i+startRow][j+startCol]-1])
                        return 0;
                    else
                        box[mat[i+startRow][j+startCol]-1] = 1;
                }
            }
        }
        return 1;
    }

    bool validRow(vector<vector<int>> &mat, int i){
        int row[9] = {0};
        for(int j=0; j<9; j++){
            if(row[mat[i][j]-1])
                return 0;
            else
                row[mat[i][j]-1] = 1;
        }
    }

    bool validCol(vector<vector<int>> &mat, int j){
        int col[9] = {0};
        for(int i=0; i<9; i++){
            if(col[mat[i][j]-1])
                return 0;
            else
                col[mat[i][j]-1] = 1;
        }
    }

    int isValid(vector<vector<int>> mat){
        for(int i=0; i<9; i++){
            if(!validRow(mat, i)) return 0;
            if(!validCol(mat, i)) return 0;
        }
        for(int i=0; i<=6; i+=3){
            for(int j=0; j<=6; j+=3){
                if(!validBox(mat, i, j)) return 0;
            }
        }
        return 1;
    }
};