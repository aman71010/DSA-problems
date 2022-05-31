#include<bits\stdc++.h>
using namespace std;

#define ll long long

struct data{
    ll zeros = 0, ones = 0;
};

class Solution{
public:
	long long m = (1e9+7);
	ll countStrings(int n) {
	    data dp[n+1];
        dp[1].zeros = 1;
        dp[1].ones = 1;
        for(int i=2; i<=n; i++){
            dp[i].zeros = (dp[i-1].zeros)%m + (dp[i-1].ones)%m;
            dp[i].ones = (dp[i-1].zeros)%m;
        }
        ll res = (dp[n].zeros + dp[n].ones) % m;
        return res;
	}
};