#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(i != largest){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int nonLeaf = n/2-1;
    for(int i=nonLeaf; i>=0; i--)
        heapify(arr,n,i);
    for(int i=n-1; i>=1; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    return;
}

int main(){
    int arr[9] = {10,12,6,8,200,3,100,15,1};
    heapSort(arr,9);  // T->O(nlogn)  S->O(1)
    for(int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    return 0;
}