#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n){
        unordered_map<int, string> kp;
        kp[2] = "abc";
        kp[3] = "def";
        kp[4] = "ghi";
        kp[5] = "jkl";
        kp[6] = "mno";
        kp[7] = "pqrs";
        kp[8] = "tuv";
        kp[9] = "wxyz";
        vector<string> res;
        string temp = "";
        solve(a, res, temp, kp, n, 0);
        return res;
    }

    void solve(int a[], vector<string> &res, string &temp, unordered_map<int, string> &kp, int n, int i){
        if(temp.length()==n){
            res.push_back(temp);
            return;
        }
        for(int j=0; j<kp[a[i]].length(); j++){
            temp.push_back(kp[a[i]][j]);
            solve(a, res, temp, kp, n, i+1);
            temp.pop_back();
        }
    }
};
