#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    //T -> O(nlog(n)) S->O(n) (for returning res vector only)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int j = 0;
        intervals.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[j][1]>=intervals[i][0])
                intervals[j][1] = max(intervals[i][1], intervals[j][1]);
            else{
                j++;
                intervals[j] = intervals[i];
            }
        }
        vector<vector<int>> res(j+1);
        for(int i=0; i<=j; i++)
            res[i] = intervals[i];
        return res;
    }
};
