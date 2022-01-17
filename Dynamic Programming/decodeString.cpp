#include<bits\stdc++.h>
using namespace std;


class Solution {
	public:
        //recursive
		int countWays(string str){
		    int n = str.length();
            if(n==0 || str[0]=='0')
                return 0;
            return solve(str, n);
		}

        int solve(string str, int n){
            if(str[0]=='0')
                return 0;
            if(n==0 || n==1)
                return 1;
            int ans = 0;
            if(str[n-1]>'0'){
                ans = solve(str, n-1);
            }
            if(str[n-2]=='1' || (str[n-2]=='2' && str[n-1]<='6'))
                ans += solve(str, n-2);
            return ans;
        }
};

class Solution {
	public:
        //dp bottom up
		long long int m = 1000000007;
		int CountWays(string str){
    	    int n = str.length();
            if(n==0 || str[0]=='0')
                return 0;
            int dp[n+1] = {0};
            dp[0] = 1;
            dp[1] = 1;
            for(int i=2; i<=n; i++){
                if(str[i-1]>'0')
                    dp[i] = (dp[i-1])%m;
                if((str[i-2]=='1' && str[i-1]>='0') || (str[i-2]=='2' && str[i-1]<='6'))
                    dp[i] = (dp[i] + dp[i-2])%m;
            }
            return dp[n];
		}
};

