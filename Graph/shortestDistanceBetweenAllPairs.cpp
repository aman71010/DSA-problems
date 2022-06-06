#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
        int n = mat.size();
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(k!=i || k!=j || i==j){
                        mat[i][j] = mat[i][j] == -1 ? INT_MAX: mat[i][j];
                        mat[i][k] = mat[i][k] == -1 ? INT_MAX: mat[i][k];
                        mat[k][j] = mat[k][j] == -1 ? INT_MAX: mat[k][j];
                        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
	}
};