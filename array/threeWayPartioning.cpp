#include<bits\stdc++.h>
using namespace std;

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b){
        int n = arr.size();
        int start = 0, end = n-1;
        int i = 0;
        while(i<=end){
            if(arr[i]<a){
                if(i>start)
                    swap(arr[i],arr[start]);
                i++;
                start++;
            } else if(arr[i]>b){
                swap(arr[i], arr[end]);
                end--;
            } else 
                i++;
        } 
    }
};