#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    // dp bottom up
    //T-> O(n^2 * k) s->O(n*k)
    int maxProfit(int k, int n, int a[]) {
        int profit[k+1][n-1];
        for(int t=0; t<=k; t++){
            for(int i=0; i<n; i++){
                if(t==0)
                    profit[t][i] = 0;
                else if(i==0)
                    profit[t][i] = 0;
                else{
                    int maxm = INT_MIN;
                    for(int j=0; j<i; j++)
                        maxm = max(maxm, profit[t-1][j] + a[i]-a[j]);
                    profit[t][i] = max(profit[t][i-1], maxm);
                }
            }
        }
        return profit[k][n-1];
    }
};