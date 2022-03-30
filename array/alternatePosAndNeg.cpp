#include<bits\stdc++.h>
using namespace std;

// T -> O(n) S -> O(n)
class Solution{
public:

	void rearrange(int arr[], int n) {
        int temp[n];
        int h = n-1, l = 0;
	    for(int i=0; i<n; i++){
            if(arr[i]<0)
                temp[h--] = arr[i];
            else
                temp[l++] = arr[i];
        }
        int i=0;
        h = n-1, l = 0;
        while(i<n){
            if(temp[l]>=0)
                arr[i++] = temp[l++];
            if(temp[h]<0)
            arr[i++] = temp[h--];
        }
        return;
	}
};

// T -> O(n*2) S -> O(1)
class Solution{
public:
    void rightRotate(int arr[], int i, int j){
        int temp = arr[j];
        for(int k=j; k>i; k++)
            arr[k] = arr[k-1];
        arr[i] = temp;
    }

	void rearrange(int arr[], int n) {
        int outOfPlace = -1;
        for(int i=0; i<n; i++){
            if(outOfPlace>=0){
                if((arr[outOfPlace]<0 && arr[i]>=0) || (arr[outOfPlace]>=0 && arr[i]<0)){
                    rightRotate(arr, outOfPlace, i);
                    if(i-outOfPlace >= 2)
                        outOfPlace += 2;
                    else
                        outOfPlace = -1;
                }
            }
            if(outOfPlace == -1){
                if((arr[i]>=0 && i%2==1) || (arr[i]<0 && i%2==0))
                    outOfPlace = i;
            }
        }
	}
};