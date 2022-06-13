#include<bits\stdc++.h>
using namespace std;



class Solution{
    public:
    //T->O(n*l)  l-> maximum word length in dict.
    string findOrder(string dict[], int n, int k) {
        vector<int> graph[k];
        for(int i=0; i<n-1; i++){
            string a = dict[i], b = dict[i+1];
            for(int j=0; j<min(a.length(),b.length()); j++){
                if(a[j]!=b[j]){
                    graph[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        return topoSort(graph, k);
    }

    string topoSort(vector<int> graph[], int k) {
	    string res;
        bool visited[k] = {0};
	    stack<int> st;
        for(int i=0; i<k; i++){
            if(!visited[i])
                dfs(graph, k, visited, i, st);
        }
        while(!st.empty()){
            res += (st.top()+'a');
            st.pop();
        }
        return res;
	}

    void dfs(vector<int> graph[], int k, bool visited[], int u, stack<int> &st){
        visited[u] = 1;
        for(int x: graph[u]){
            if(!visited[x]){
                dfs(graph, k, visited, x, st);
            }
        }
        st.push(u);
    }
};