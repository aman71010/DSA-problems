#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    //T -> O(n^k) s->O(n)
    string findMaximumNum(string str, int k){
        string res = str;
        solve(str, k, res, 0);
        return res;
    }
    void solve(string str, int k, string &res, int curr){
        if(k==0)
            return;
        char maxD = str[curr];
        for(int j=curr+1; j<str.length(); j++)
            if(maxD < str[j])
                maxD = str[j];
        if(maxD!=str[curr])
                k = k-1;
        for(int j=str.length()-1; j>=curr; j--){
            if(maxD==str[j]){
                swap(str[curr], str[j]);
                if(str.compare(res)>0)
                    res = str;
                solve(str, k, res, curr+1);
                swap(str[curr], str[j]);
            }
        }
    }
};