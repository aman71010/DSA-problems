#include<bits\stdc++.h>
using namespace std;

class Solution{
	public:
	int numSquares(int n){
		if(sqrt(n)-floor(sqrt(n)) == 0) return 1;
		if(n <= 3) return n;
		int res = n;
		for(int i=1; i<=n; i++){
			int temp = i*i;
			if(temp>n) break;
			else
				res = min(res, 1+numSquares(n-temp));
		}
		return res;
	}
};


// bottom up
class Solution {
public:
    int numSquares(int n) {
        if(sqrt(n)-floor(sqrt(n)) == 0) return 1;
		if(n <= 3) return n;
		int *dp = new int[n+1];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for(int i=4; i<=ceil(sqrt(n)); i++){
			dp[i] = i;
			for(int j=1; j<=i; j++){
				int temp = j*j;
				if(temp>i) break;
				else
					dp[i] = min(dp[i], 1+dp[i-temp]);
			}
		}
        int res = dp[n];
        delete[] dp;
		return res;
    }
};

// topdown approach
class Solution{
	public:
	int solve(int n, int *dp){
		if(dp[n] != INT_MAX)
			return dp[n];
		for(int i=1; i<=n; i++){
			int temp = i*i;
			if(temp>n) break;
			else
				dp[n] = min(dp[n], 1+solve(n-temp, dp));
		}
		return dp[n];
	}

	int numSquares(int n){
		if(sqrt(n)-floor(sqrt(n)) == 0) return 1;
		if(n <= 3) return n;
		int *dp = new int[n+1];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for(int i=4; i<=n; i++){
			dp[i] = INT_MAX;
		}
		int res = solve(n, dp);
		delete[] dp;
		return res;
	}
};