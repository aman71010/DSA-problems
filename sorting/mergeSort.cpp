#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int *left = new int[n1];
    int *right = new int[n2];
    for(int i=0; i<n1; i++){
        left[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        right[j] = arr[m+1+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int l, int r){
    if(l>=r)
        return;
    int m = l+(r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(){
    int arr[9] = {10,12,6,8,200,3,100,15,1};
    mergeSort(arr,0,8);  // T->O(nlogn)  S->O(n)
    for(int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    return 0;
}