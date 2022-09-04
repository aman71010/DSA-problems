#include<bits\stdc++.h>
using namespace std;


// T-> O(32*n*log(m)) S-> O(1)
class Solution{   
public:

    int search(vector<int>&arr, int tar){
        int l = 0, h = arr.size()-1, m;
        int res = 0;
        while(l<=h){
            m = l + (h-l)/2;
            if(arr[m]<=tar){
                l = m+1;
                res = m+1;
            } else
                h = m-1;
        }
        return res;
    }
    
    int median(vector<vector<int>> &mat, int n, int m){
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for(int i=0; i<n; i++){
            minm = min(minm, mat[i][0]);
            maxm = max(maxm, mat[i][m-1]);
        }
        int desiredCount = (n*m+1)/2;
        while(minm<maxm){
            int mid = minm + (maxm-minm)/2;
            int count = 0;
            for(int i=0; i<n; i++)
                count += search(mat[i], mid);
            if(count < desiredCount)
                minm = mid+1;
            else
                maxm = mid;
        }
        return minm;
    }
};