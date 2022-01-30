#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    //clockwise rotation
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int g=0; g<n; g++){
            for(int i=g, j=0; i<n; i++,j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};

class Solution {
public:
    //clockwise rotation
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-1-i; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
        }
    }
};