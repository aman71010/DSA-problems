#include<bits\stdc++.h>
using namespace std;

// naive (recurrsion)
class Solution{
	public:
    int maxSumIS(int arr[], int n){  
        return solve(arr, n, INT_MAX);
	}  

    int solve(int arr[], int n, int val){
        if(n==0)
            return 0;
        if(arr[n-1]>val)
            return solve(arr, n-1, val);
        return max(solve(arr, n-1, val), arr[n-1]+solve(arr, n-1, arr[n-1]));
    }
};

// dp
class Solution{
	public:
	int maxSumIS(int arr[], int n){  
	    int msis[n];
        for(int i=0; i<n; i++)
            msis[0] = arr[0];
        for(int i=1; i<n; i++){
            msis[i] = arr[i];
            for(int j=0; j<i; j++){
                if(arr[i]>arr[j] && msis[i]<msis[j]+arr[i]){
                    msis[i] = msis[j]+arr[i];
                }
            }
        }
        int ans = msis[0];
        for(int i=1; i<n; i++){
            if(msis[i]>ans){
                ans = msis[i];
            }
        }
        return ans;
	}  
};