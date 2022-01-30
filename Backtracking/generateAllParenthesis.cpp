#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        string s="";
        solve(res, s, n, 0, 0);
        return res;
    }

    void solve(vector<string> &res, string s, int n, int on, int cn){
        if(on == n && cn == n){
            res.push_back(s);
            return;
        }
        if(cn < on)
            solve(res, s+")", n, on, cn+1);
        if(on < n)
            solve(res, s+"(", n, on+1, cn);
    }
};