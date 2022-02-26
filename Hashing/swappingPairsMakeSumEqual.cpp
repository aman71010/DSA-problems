#include<bits\stdc++.h>
using namespace std;

class Solution{

	public:
    //T->O(nlogn + mlogm)
	int findSwapValues(int A[], int n, int B[], int m){
        sort(A, A+n);
        sort(B, B+m);
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++)
            sum1 += A[i];
        for(int i=0; i<m; i++)
            sum2 += B[i];
        if((sum1-sum2)%2 != 0)
            return -1;
        int diff = (sum1-sum2)/2;
        int i=0, j=0;
        while(i<n && j<m){
            int d = A[i]-B[j];
            if(d < diff)
                i++;
            else if(d > diff)
                j++;
            else
                return 1;
        }
        return -1;
	}
};


class Solution{

	public:
    //T->O(n+m) S->O(m)
	int findSwapValues(int A[], int n, int B[], int m){
        if(n<m)
            findSwapValues(B, m, A, n);
        unordered_set<int> s;
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++)
            sum1 += A[i];
        for(int i=0; i<m; i++){
            s.insert(B[i]);
            sum2 += B[i];
        }
        if((sum1-sum2)%2 != 0)
            return -1;
        int dif = (sum1-sum2)/2;
        for(int i=0; i<n; i++){
            int d = A[i]-dif;
            if(s.find(d)!=s.end())
                return 1;
        }
        return -1;
	}
};