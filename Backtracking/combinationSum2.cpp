#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(A, res, temp, 0, 0, B);
        return res;
    }

    void solve(vector<int> &A, vector<vector<int>> &res, vector<int> &temp, int sum, int l, int k){
        if(sum==k){
            res.push_back(temp);
            return;
        }
        for(int i=l; i<A.size(); i++){
            if(sum+A[i]>k)
                break;
            if(i>l && A[i]==A[i-1])
                continue;
            temp.push_back(A[i]);
            solve(A, res, temp, sum+A[i], i+1, k);
            temp.pop_back();
        }
    }    
};