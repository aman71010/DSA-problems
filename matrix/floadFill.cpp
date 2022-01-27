#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            dfs(image, sr, sc, image[sr][sc], newColor, image.size(), image[0].size());
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor, int m, int n){
        if(i<0 ||  j<0 || i>=m || j>=n || image[i][j]!=oldColor)
            return;
        image[i][j] = newColor;
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};
        for(int k=0; k<4; k++)
            dfs(image, i+x[k], j+y[k], oldColor, newColor, m, n);
    }
};