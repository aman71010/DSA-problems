#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) S-> O(1)
int max_sum(int arr[],int n){
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int temp = arr[0];
        int sum = 0;
        for(int j=1; j<n; j++){
            arr[j-1] = arr[j];
            sum += (j-1)*arr[j-1];
        }
        arr[n-1] = temp;
        sum += (n-1)*arr[n-1];
        ans = max(ans, sum);
    }
    return ans;
}

// T-> O(n) S-> O(1)

int max_sum(int arr[],int n){
    int currVal = 0;
    int arrSum = 0;
    for(int i=0; i<n; i++){
        arrSum += arr[i];
        currVal += i*arr[i];
    }
    int ans = currVal;
    for(int i=1; i<n; i++){
        int nextVal = currVal - (arrSum-arr[i-1]) + (n-1)*arr[i-1];
        currVal = nextVal;
        ans = max(ans, nextVal);
    }
    return ans;
}
