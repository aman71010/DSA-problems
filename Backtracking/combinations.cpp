#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    void combination(vector<vector<int>>& res, vector<int>& temp, int n, int k, int start){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        else {
            for(int i=start; i<=n-k+i; i++){
                temp.push_back(i);
                combination(res, temp, n, k, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        combination(res, temp, n, k, 1);
        return res;
    }
};