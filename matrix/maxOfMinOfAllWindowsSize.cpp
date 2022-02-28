#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find maximum of minimums of every window size.
	//T-O(n*2) S->O(n)
    vector <int> maxOfMin(int arr[], int n){
        vector<int> res(n);
		for(int i=0; i<n; i++){
			int minm = INT_MAX;
			int k = 0;
			for(int j=i; j<n; j++){
				minm = min(minm, arr[j]);
				res[k] = max(res[k], minm);
				k++;
			}
		}
		return res;
    }
};


class Solution{
    public:
    //Function to find maximum of minimums of every window size.
	//T-O(n) S->O(n)

    vector<int> maxOfMin(int arr[], int n){
        vector<int> res(n);
		int left[n], right[n];
		for(int i=0; i<n; i++){
			left[i] = -1;
			right[i] = n;
		}
		stack<int> st;
		for(int i=0; i<n; i++){
			while(!st.empty() && arr[st.top()]>=arr[i])
				st.pop();
			if(!st.empty())
				left[i] = st.top();
			st.push(i);
		}
		while(!st.empty())
			st.pop();
		for(int i=n-1; i>=0; i--){
			while(!st.empty() && arr[st.top()]>=arr[i])
				st.pop();
			if(!st.empty())
				right[i] = st.top();
			st.push(i);
		}
		for(int i=0; i<n; i++){
			int windLen = right[i]-left[i]-1;
			res[windLen-1] = max(res[windLen-1], arr[i]);
		}
		for(int i=n-2; i>=0; i--){
			res[i] = max(res[i], res[i+1]);
		}
		return res;
    }
};