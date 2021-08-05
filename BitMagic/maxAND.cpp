#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:	
	
	int matchPattern(int pattern, int arr[], int n){
	    int cnt=0; 
	    for(int i=0; i<n; i++){
	        if((pattern & arr[i]) == pattern){
	            cnt++;
	            if(cnt==2) break;
	        }
	    }
	    return cnt;
	}
	// Function for finding maximum and value pair
	int maxAND (int arr[], int n)
	{
	    int res=0, cnt, maxEle = arr[0];
	    for(int i=1; i<n; i++){
	        maxEle = max(maxEle, arr[i]);
	    }
	    int k=log2(maxEle);
	    for(int i=k; i>=0; i--){
	        cnt = matchPattern((res|(1<<i)), arr, n);
	        if(cnt>=2)
	            res = res|(1<<i);
	    }
	    return res;
	}
};

int main(){
    return 0;
}