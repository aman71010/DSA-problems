#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        sort(A.begin(), A.end());
        for(int i=1; i<A.size(); i++){
            if(A[i]==A[i-1]){
                A.erase(A.begin()+i);
                i--;
            }
        }
        // for(int i=0; i<A.size(); i++){
        //     cout << A[i] << " ";
        // }
        // cout << endl;

        vector<vector<int>> res;
        vector<int> temp;
        solve(A, res, temp, B, 0);
        return res;
    }
    
    void solve(vector<int> &A, vector<vector<int>> & res, vector<int> &temp, int sum, int i){
        if(sum==0){
            res.push_back(temp);
            return;
        }
        while(i<A.size() && sum-A[i]>=0){
            temp.push_back(A[i]);
            solve(A, res, temp, sum-A[i], i);
            i++;
            temp.pop_back();
        }
    }
};