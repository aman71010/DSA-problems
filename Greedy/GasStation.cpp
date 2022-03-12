#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, currGas = 0, ans = 0;
        for(int i=0; i<n; i++){
            totalGas += gas[i]-cost[i];
            currGas += gas[i]-cost[i];
            if(currGas<0){
                currGas = 0;
                ans = i+1;
            }
        }
        if(totalGas < 0)
            return -1;
        else
            return ans;
    }
};