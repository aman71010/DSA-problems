#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h){
    int pivort = arr[h];
    int j = -1;
    for(int i=0; i<h; i++){
        if(arr[i]<=pivort){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[h]);
    return j+1;
}

void quickSort(int arr[], int l, int h){
    if(l>=h)
        return;
    int pivortIdx = partition(arr,l,h);
    quickSort(arr,l,pivortIdx-1);
    quickSort(arr,pivortIdx+1,h);
}

int main(){
    int arr[9] = {10,12,6,8,200,3,100,15,1};
    quickSort(arr,0,8);  // T->O(nlogn)  S->O(1)
    for(int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    return 0;
}