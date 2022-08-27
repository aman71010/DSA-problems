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
    // T-> O(N*2) S-> O(N)
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


class Solution {
    public:
    
    struct compare {
        bool operator()(Job &a, Job &b){
            return a.profit<b.profit;
        }
    };
    // T-> O(N*logN) S-> O(N)
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, [&](Job &a, Job&b){
            return a.dead<b.dead;
        });
        priority_queue<Job, vector<Job>, compare> maxHeap;
        vector<Job> results;
        int slotsAvailable = 0;
        for(int i=n-1; i>=0; i--){
            if(i == 0)
                slotsAvailable = arr[i].dead;
            else
                slotsAvailable = arr[i].dead-arr[i-1].dead;
            maxHeap.push(arr[i]);
            while(slotsAvailable>0 && maxHeap.empty()==false){
                results.push_back(maxHeap.top());
                maxHeap.pop();
                slotsAvailable--;
            }
        }
        int profit = 0, count = results.size();
        for(int i=0; i<results.size(); i++){
            profit += results[i].profit; 
        }
        return {count, profit};
    } 
};