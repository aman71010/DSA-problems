#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //T = O(n) S = O(n) using stack
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            while(!st.empty() and t[i] > t[st.top()]) {    
                ans[st.top()] = i - st.top();           
                st.pop();
            }
            st.push(i);                                
        }
        return ans;
    }
    
    //T = O(n) S = O(1) without using stack
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; i--) {
            int next = i+1;
            while( next < n &&  t[next] <= t[i]) {    
                next += ans[next]? ans[next]: n;
            }
            if(next<n) ans[i] = next-i;
                                           
        }
        return ans;
    }
};