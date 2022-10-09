#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int k = arr[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(arr[j]>k)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = k;
    }
}

int main(){
    int arr[9] = {10,12,6,8,200,3,100,15,1};
    insertionSort(arr,9);  // T->O(n^2)  S->O(1)
    for(int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    return 0;
}