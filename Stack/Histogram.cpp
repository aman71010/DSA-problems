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