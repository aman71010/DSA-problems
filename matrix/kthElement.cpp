#include<bits\stdc++.h>
using namespace std;

// T-> O(klogn) s-> O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            minHeap.push({matrix[0][i], {0, i}});
        }
        int ans;
        for(int i=0; i<k; i++){
            auto tmp = minHeap.top();
            minHeap.pop();
            ans = tmp.first;
            int row = tmp.second.first;
            int col = tmp.second.second;
            if(row+1<n)
                minHeap.push({matrix[row+1][col], {row+1, col}});
        }
        return ans;
    }
};