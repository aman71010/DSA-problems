#include<bits\stdc++.h>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        int res = INT_MIN;
        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] += dp[i-1][j];
            }
        }
        for(int i=0; i<n; i++){
            res = max(res, largestRectangleArea(dp[i]));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int prev[n];
        int next[n];
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            prev[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            next[i] = st.empty()? n: st.top();
            st.push(i);
        }
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++)
            maxArea = max(maxArea, (next[i]-prev[i]-1)*heights[i]);
        return maxArea;
    }
};