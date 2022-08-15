#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int merge(vector<int>& arr, int l, int m, int r){
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
        i=0, j=0;
        int count = 0;
        while(i<n1 && j<n2){
            if(ceil((double) left[i]/2) > right[j]){
                count += (n1-i);
                j++;
            } else
                i++;
        }
        delete[] left;
        delete[] right;
        return count;
    }

    int mergeSort(vector<int>& arr, int l, int r){
        if(l>=r)
            return 0;
        int m = l+(r-l)/2;
        return mergeSort(arr, l, m) + mergeSort(arr, m+1, r) + merge(arr, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        int res = mergeSort(nums, 0, nums.size()-1);
        return res;
    }
};