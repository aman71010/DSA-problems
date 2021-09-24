#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    int maxDistinctNum(int arr[], int n, int k){
    	unordered_set<int> s;
        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        int m = s.size();
        int dif = n-m;
        if(dif==0) return n-k;
        else
            return m;
    }
};