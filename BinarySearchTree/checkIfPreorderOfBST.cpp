#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:

    //------------------------- t-> O(n) and s-> O(n) ----------------------------
    int canRepresentBST(int arr[], int n) {
        int root = INT_MIN;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(arr[i]<root)
                return false;
            while(!st.empty() && st.top()<arr[i]){
                root = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return true;
    }
};