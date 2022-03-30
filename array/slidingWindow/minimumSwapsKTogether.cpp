#include<bits\stdc++.h>
using namespace std;


class Solution{
public:
    // T-> O(n) and S-> O(1)
    int minSwap(int arr[], int n, int k) {
        int lk = 0, gk = 0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k) lk++;
        }
        int start = 0, end = lk-1;
        for(int i=0; i<=lk; i++){
            if(arr[i]>k) gk++;
        }
        int res = gk;
        while(end<n-1){
            start++;
            end++;
            if(arr[end]>k) gk++;
            if(arr[start-1]>k) gk--;
            res = min(res, gk);
        }
        return res;

    }
};