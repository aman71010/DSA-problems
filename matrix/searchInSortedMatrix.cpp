#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    // T-> O(m+n) s->O(1)
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(mat[i][j] < x)
                i++;
            else if(mat[i][j] > x)
                j--;
            else
                return 1;
        }
        return 0;
    }
};