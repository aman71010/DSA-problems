#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<vector<int>> queriesPair;
        for(int i=0; i<m; i++)
            queriesPair.push_back({queries[i], i});
        sort(items.begin(), items.end());
        sort(queriesPair.begin(), queriesPair.end());
        vector<int> res(m, 0);
        int j = 0, maxB = 0;
        for(int i=0; i<m; i++){
            int p = queriesPair[i][0];
            while(j<n && p>=items[j][0]){
                maxB = max(maxB, items[j][1]);
                j++;
            }
            res[queriesPair[i][1]] = maxB;
        }
        return res;
    }
};