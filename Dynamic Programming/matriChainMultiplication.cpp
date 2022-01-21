#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    //recursive
    int matrixMultiplication(int n, int arr[]){
        return matrixChainMultiplication(arr, 1, n-1);
    }

    int matrixChainMultiplication(int arr[], int i, int j){
        if(i==j)
            return 0;
        int res = INT_MAX;
        int count = 0;
        for(int k=i; k<j; k++){
            count = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            res = min(res, count);
        }
        return res;
    }
};

class Solution{
public:
    //dp top down 
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return matrixChainMultiplication(arr, 1, n-1, dp);
    }

    int matrixChainMultiplication(int arr[], int i, int j, vector<vector<int>> &dp){
        if(i==j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        int count = 0;
        for(int k=i; k<j; k++){
            count = matrixChainMultiplication(arr, i, k, dp) + matrixChainMultiplication(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
            dp[i][j] = min(dp[i][j], count);
        }
        return dp[i][j];
    }
};

class Solution{
public:
    //dp bottom up 
    int matrixMultiplication(int n, int arr[]){
        int dp[n][n];
        int count;
        for(int g=1; g<n; g++){
            for(int i=1,j=g; j<n; i++,j++){
                if(g==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++){
                    count = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if(dp[i][j]>count)
                        dp[i][j] = count;
                }
            }
        }
        return dp[1][n-1];
    }
};