#include <bits\stdc++.h>
using namespace std;

class Solution{
    public:
    int closest3Sum(int A[], int n, int X)
    {
        sort(A, A+n);
        int res = A[0]+A[1]+A[2];
        for(int i=0; i<n-2; i++){
            int l = i+1, h = n-1;
            while(l<h){
                int currSum = A[i]+A[l]+A[h];
                if(currSum < X)
                    l++;
                else if(currSum > X)
                    h--;
                else 
                    return X;
                if(abs(X-currSum) < abs(X-res))
                    res = currSum;
            }
        }
        return res;
    }
};