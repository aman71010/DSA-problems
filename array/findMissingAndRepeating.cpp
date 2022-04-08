#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *res = new int[2];
        int i=0;
        while(i<n){
            while(arr[i]-1 != i){
                if(arr[arr[i]-1] == arr[i]){
                    break;
                } else {
                    swap(arr[i], arr[arr[i]-1]);
                }
            }
            i++;
        }
        for(int i=0; i<n; i++){
            if(arr[i]-1!=i){
                res[0] = arr[i];
                res[1] = i+1;
            }
        }
        return res;
    }
};

// T-> O(n) S-> O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xy = arr[0];
        for(int i=1; i<n; i++)
            xy ^= arr[i];
        for(int i=1; i<=n; i++)
            xy ^= i;
        int rmsb = xy & ~(xy-1);
        int a = 0, b = 0;
        for(int i=0; i<n; i++){
            if(rmsb & arr[i])
                a ^= arr[i];
            else
                b ^= arr[i];
        }
        for(int i=1; i<=n; i++){
            if(rmsb & i)
                a ^= i;
            else
                b ^= i;
        }
        int *res = new int[2];
        bool flag = false;
        for(int i=0; i<n; i++){
            if(a == arr[i]){
                flag = true;
                break;
            }
        }
        
        if(flag){
            res[0] = a;
            res[1] = b;
        }
        else{
            res[0]= b;
            res[1] = a;
        }
        // cout << a << " " << b << endl;
        return res;
    }
};