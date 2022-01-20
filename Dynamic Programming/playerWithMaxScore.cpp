#include<bits\stdc++.h>
using namespace std;


class Solution{   
public:
    // dp T-> O(n*n) S->O(n*n)
    bool is1winner(int n,int arr[]) {
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += arr[i];
        int dp[n][n];
        for(int g=0; g<n; g++){
            for(int i=0,j=g; j<n; i++,j++){
                if(g==0)
                    dp[i][j] = arr[i];
                else if(g==1)
                    dp[i][j] = max(arr[i],arr[j]);
                else{
                    int poss1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    int poss2 = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
                    dp[i][j] = max(poss1, poss2);
                }
            }
        }
        if(dp[0][n-1]>=sum-dp[0][n-1])
            return 1;
        return 0;
    }
};