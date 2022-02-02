#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int arr[9] = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> temp;
        solve(arr,k,n,res,temp,0);
        return res;
    }
    
    void solve(int arr[], int k, int n, vector<vector<int>> &res, vector<int> temp, int l) {
        if(k==0 && n==0){
            res.push_back(temp);
            return;
        }
        for(int i=l; i<9; i++){
            if(k<=0) break;
            if(n-arr[i]<0) break;
            temp.push_back(arr[i]);
            solve(arr, k-1, n-arr[i], res, temp, i+1);
            temp.pop_back();
        }
    }
    
    
};