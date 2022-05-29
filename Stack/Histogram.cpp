#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        int tp, i=0; 
        long long maxArea=INT_MIN;
        long long areaWithTop;
        while(i<n){
            if(st.empty() || arr[st.top()]<=arr[i])
                st.push(i++);
            else{
                tp = st.top();
                st.pop();
                areaWithTop = arr[tp]*st.empty() ? i: i-st.top()-1;
                if(maxArea<areaWithTop)
                    maxArea=areaWithTop;
            }

        }
        while(!st.empty()){
            tp = st.top();
            st.pop();
            areaWithTop = arr[tp]*st.empty() ? i: i-st.top()-1;
            if(maxArea<areaWithTop)
               maxArea=areaWithTop;
        }
        return maxArea;
    }
};

int main(){
    return 0;
}


// T-> O(n) s-> O(n)
class Solution {
public:
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