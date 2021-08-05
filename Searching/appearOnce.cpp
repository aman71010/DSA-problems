#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    int search(int arr[], int n){
	    int l=0,  h=n-1;
	    while(l<h){
	        int m = l + (h-l)/2;
	        if(m%2==0){
	            if(arr[m]==arr[m+1])
	                l = m+2;
	            else
	                h = m;
	        }
	        else{
	           if(arr[m]==arr[m-1])
	                l = m+1;
	            else
	                h = m-1;
	        }
	    }
	    return arr[l];
	}
};

int main(){
    return 0;
}