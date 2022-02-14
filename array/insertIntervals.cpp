#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = 0, h = n-1, m;
        while(l<=h){
            m = l+(h-l)/2;
            if(intervals[m][0]<newInterval[0])
                l = m+1;
            else if(intervals[m][0]>newInterval[0])
                h = m-1;
            else{
                intervals[m][1] = max(newInterval[1], intervals[m][1]);
                return merge(intervals);
            }
        }
        vector<vector<int>> newIntervalList;
        for(int i=0; i<=h; i++)
            newIntervalList.push_back(intervals[i]);
        newIntervalList.push_back(newInterval);
        for(int j=l; j<n; j++)
            newIntervalList.push_back(intervals[j]);
        return merge(newIntervalList);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
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