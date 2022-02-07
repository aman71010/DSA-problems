#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int n = s.length();
        solve(res, temp, s, n, 0);
        return res;
    }

    void solve(vector<vector<string>> &res, vector<string> &temp, string s, int n, int start){
        if(start>=n){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<n; i++){
            if(isPalindrome(s, start, i)){
                temp.push_back(s.substr(start, i-start+1));
                solve(res, temp, s, n, i+1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int h){
        while(l<h){
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
};