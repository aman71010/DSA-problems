#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/

    int maxHeight(int height[],int width[],int length[],int n){
        vector<vector<int>> box(3*n, vector<int> (3, 0));
        int ind = 0;
        for(int i=0; i<n; i++){
            box[ind][0] = height[i];
            box[ind][1] = max(width[i],length[i]);
            box[ind][2] = min(width[i],length[i]);
            ind++;
            box[ind][0] = width[i];
            box[ind][1] = max(height[i],length[i]);
            box[ind][2] = min(height[i],length[i]);
            ind++;
            box[ind][0] = length[i];
            box[ind][1] = max(width[i],height[i]);
            box[ind][2] = min(width[i],height[i]);
            ind++;
        }
        sort(box.begin(), box.end(), [&](const vector<int> &a,const vector<int> &b){return a[1]*a[2] > b[1]*b[2];});
        int mhs[3*n];
        for(int i=0; i<3*n; i++){
            mhs[i] = box[i][0];
            for(int j=0; j<i; j++){
                if(box[i][1]<box[j][1] && box[i][2]<box[j][2] && mhs[i]<mhs[j]+box[i][0])
                    mhs[i] = mhs[j]+box[i][0];
            }
        }
        int ans = 0;
        for(int i=0; i<3*n; i++)
            ans = max(ans, mhs[i]);
        return ans;
    }
};