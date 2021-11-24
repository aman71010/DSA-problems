#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //T = O(n+m) S = O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while(i<n && j<m){
            int As = firstList[i][0], Ae = firstList[i][1], Bs = secondList[j][0], Be = secondList[j][1];
            if(As<=Be && Bs<=Ae)
                res.push_back({max(As, Bs), min(Ae, Be)});
            Ae<Be ? i++: j++;
        }
        return res;
    }
};