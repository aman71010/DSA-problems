#include<bits\stdc++.h>
using namespace std;

struct Job 
{ 
    int id; 
    int dead;  
    int profit;
};

class Solution 
{
    public:
    static bool compare(Job a, Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    // T-> O(N*N) S-> O(N)
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compare);
        int results[n];
        bool slots[n] = {0};
        for(int i=0; i<n; i++){
            for(int j=min(n,arr[i].dead)-1; j>=0; j--){
                if(!slots[j]){
                    results[j] = i;
                    slots[j] = true;
                    break;
                }
            }
        }
        int profit = 0, count = 0;
        for(int i=0; i<n; i++){
            if(slots[i]){
                profit += arr[results[i]].profit;
                count++;
            }
                
        }
        return {count, profit};
    } 
};