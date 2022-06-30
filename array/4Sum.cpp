#include <bits\stdc++.h>
using namespace std;

// T-> O(n^3) and S-> O(1)
bool find4Numbers(int arr[], int n, int x)  {
    sort(arr, arr+n);
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int t = x-arr[i]-arr[j];
            int l = j+1, r = n-1;
            while(l<r){
                if(arr[l]+arr[r] == t)
                    return 1;
                else if(arr[l]+arr[r] < t)
                    l++;
                else
                    r--;
            }
        }
    }
    return 0;
} 

// T-> O(n^2) and S-> O(n^2)
bool find4Numbers(int arr[], int n, int x)  {
    unordered_map<int, pair<int,int>> ump;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            ump[arr[i]+arr[j]] = {i,j};
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int num = x-(arr[i]+arr[j]);
            if(ump.find(num) != ump.end()){
                auto pr = ump[num];
                if(i != pr.first && i != pr.second && j != pr.first && j != pr.second)
                    return 1;
            }
        }
    }
    return 0;
} 