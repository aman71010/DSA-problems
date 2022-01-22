#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
	int minDifference(int a[], int n)  { 
	    int sum = 0;
	    int mdiff = INT_MAX;
        for(int i=0; i<n; i++)
            sum += a[i];
        int dp[sum+1][n+1];
        for(int j=0; j<=n; j++)
            dp[0][j] = true;
        for(int i=1; i<=sum; i++)
            dp[i][0] = false;
        for(int i=1; i<=sum; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = dp[i][j-1];
                if(i>=a[j-1])
                    dp[i][j] = dp[i][j-1] || dp[i-a[j-1]][j-1];
                if(dp[i][j]){
                    int secSum = sum-i;
                    mdiff = min(mdiff, abs(i-secSum));
                }
            }
        }
        return mdiff;
	}
};

