#include<bits/stdc++.h>
using namespace std;


// recurrsion
class Solution {
public:
    
    int getFactorial(int n){
        int ans = 1;
        for(int i=2; i<=n; i++)
            ans *= i;
        return ans;
    }
    
    void solve(string s, string &res, int k){
        int n = s.length();
        if(n==1){
            res += s[0];
            return;
        }
        int f = getFactorial(n-1);
        int block = k/f;
        int pos = k%f;
        res += s[block];
        s.erase(s.begin()+block);
        solve(s, res, pos);
    }

    string getPermutation(int n, int k) {
        string s, res;
        for(int i=1; i<=n; i++)
            s += (i+'0');
        solve(s, res, k-1);
        return res;
    }
};


// iterative
class Solution {
public:
    string getPermutation(int n, int k) {
        string s, res;
        k = k-1;
        for(int i=1; i<=n; i++)
            s += (i+'0');
        int fac = 1;
        for(int i=2; i<n; i++)
            fac *= i;
        while(true){
            int block = k/fac;
            res += s[block];
            s.erase(s.begin()+block);
            if(s.size() == 0) break;
            k = k%fac;
            fac /= s.size();
        }
        return res;
    }
};