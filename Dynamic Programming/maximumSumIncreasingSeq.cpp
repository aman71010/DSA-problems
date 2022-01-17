#include<bits\stdc++.h>
using namespace std;

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
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