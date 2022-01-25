#include<bits\stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, [&](Item &a, Item &b){
            double rat1 = (double)a.value/(double)a.weight, rat2 = (double)b.value/(double)b.weight;
            return rat1>rat2;
        });
        
        double ans = 0.0;
        for(int i=0; i<n; i++){
            if(arr[i].weight<=W){
                ans+=arr[i].value;
                W-=arr[i].weight;
            } else{
                double val = arr[i].value, wei = arr[i].weight;
                ans += W*(val/wei);
                break;
            }   
        }
        return ans;
    }
};