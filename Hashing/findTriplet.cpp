#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A+n);
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            while(l<n){
                int sum = A[i]+A[l]+A[r];
                if(sum==X) 
                    return 1;
                else if(sum<X)
                    l++;
                else
                    r--;
            }
        }
        return 0;
    }

    //another solution;

    bool find3Numbers(int A[], int n, int X)
    {
        for(int i=0; i<n-2; i++){
            unordered_set<int> s;
            int sum = X-A[i];
            for(int j=i+1; j<n; j++){
                if(s.find(sum-A[j])!=s.end()){
                    return 1;
                }
                s.insert(A[j]);
            }
        }
        return 0;
    }
};

int main(){
    return 0;
}