#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //--------------T = exponentail----------------------
    int countWays(int coins[], int m, int N)
    {
        
    }

    //---------------------T = O(N*m) and S=O(N)-------------

    int countWays(int m, int N)
    {
        int dp[N+1];
        dp[0] = 1;
        for(int i=1; i<=N; i++){
            dp[i] = 0;
            for(int j=1; j<=m && j<=i; j++){
                dp[i] += dp[i-j];
            }
        }
        return dp[N];
    }

    //----------------------O(N)---------O(N)---------------------------
    int countWays(int m, int N)
    {
        int arr[N+1];
        arr[0] = 1;
        int sum=0;
        for(int i=1; i<=N; i++){
            int s = i-m-1;
            int e = i-1;
            if(s>0){
                sum-=arr[s];
            }
            sum+=arr[e];
            arr[i]=sum;
        }
        return arr[N];
    }

    
    
};