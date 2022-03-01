#include<bits\stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    // T-> O(nlogn) S-> O(n)
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
        vector<pair<int,int>> orgPos;
        for(int i=0; i<n; i++)
            orgPos.push_back({nums[i],i});
        sort(orgPos.begin(), orgPos.end());
        bool visited[n] = {0};
        int ans = 0;
        for(int i=0; i<n; i++){
            if(visited[i] && orgPos[i].second == i)
                continue;
            int j = i;
            int cycleSize = 0;
            while(!visited[j]){
                visited[j] = 1;
                j = orgPos[j].second;
                cycleSize++;
            }
            if(cycleSize>0)
                ans += (cycleSize-1);
        }
        return ans;
	}
};
