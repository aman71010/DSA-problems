#include<bits\stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n){
        if(n==1)
            return 1;
        vector<vector<int>> arr(n, vector<int>(2));
        for(int i=0; i<n; i++){
            arr[i][0] = start[i];
            arr[i][1] = end[i];
        }
        sort(arr.begin(), arr.end(), [&](const vector<int> &a, const vector<int> &b){return a[1]<b[1];});
        int i = 0, j = 1, ans = 1;
        while(i<n && j<n){
            if(arr[i][1]<arr[j][0]){
                i = j;
                j++;
                ans++;
            }
            else
                j++;
        }
        return ans;
    }
};