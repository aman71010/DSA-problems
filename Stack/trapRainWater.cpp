#include<bits\stdc++.h>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left[n], right[n];
        left[0] = height[0];
        for(int i=1; i<n; i++)
            left[i] = max(left[i], left[i-1]);
        right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i], right[i+1]);
        for(int i=1; i<n-1; i++){
            res += (min(left[i], right[i]) - height[i]);
        }
        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int pH = st.top();
                st.pop();
                if(st.empty()) break;
                int minH = min(height[st.top()], height[i]) - height[pH];
                int dis = i-st.top()-1;
                res += (dis*minH);
            }
            st.push(i);
        }
        return res;
    }
};