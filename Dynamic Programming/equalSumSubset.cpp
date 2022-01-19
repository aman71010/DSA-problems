#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.

    //recursive
    bool findPartition(int a[], int n){
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += a[i];
        if(sum&1) return false;
        return equalSumSubset(a, sum/2, n);
    }

    bool equalSumSubset(int a[], int sum, int n){
        if(sum == 0)
            return true;
        if(n==0 && sum!=0)
            return false;
        if(a[n-1]>sum)
            return equalSumSubset(a, sum, n-1);
        return equalSumSubset(a, sum-a[n-1], n-1);
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.

    //dp bottom up T->O(sum*N) S-> O(sum*N)
    bool findPartition(int a[], int n){
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += a[i];
        if(sum&1) return false;
        int hs = sum/2;
        int dp[hs+1][n+1];
        for(int j=0; j<=n; j++)
            dp[0][j] = true;
        for(int i=1; i<=hs; i++)
            dp[i][0] = false;
        for(int i=1; i<=hs; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = dp[i][j-1];
                if(i>=a[j-1])
                    dp[i][j] = dp[i][j-1] || dp[i-a[j-1]][j-1];
            }
        }
        return dp[hs][n];
    }
};

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.

    //dp bottom up T->O(sum*N) S-> O(sum*N)
    bool findPartition(int a[], int n){
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += a[i];
        if(sum&1) return false;
        int hs = sum/2;
        int dp[hs+1];
        for(int i=0; i<=hs; i++)
            dp[i] = false;
        for(int i=0; i<=n; i++){
            for(int j=hs; j>=a[i]; j--){
                if(dp[j-a[i]]==1 || a[i]==j)
                    dp[j] = true;
            }
        }
        return dp[hs];
    }
};