#include<bits\stdc++.h>
using namespace std;

//kosaraju's Algo
// T-> O(V+E)
class Solution{
	public:

    public:
	void dfs(int u, vector<int> adj[], vector<bool>& vis, stack<int>& st){
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                dfs(v, adj, vis, st);
            }
        }
        st.push(u);
    }

    void transposeGraph(int V, vector<int> adj[], vector<int> revAdj[]){
        for(int i=0; i<V; i++){
            for(int v: adj[i])
                revAdj[v].push_back(i);
        }
    }

    int kosaraju(int V, vector<int> adj[]){
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(i, adj, vis, st);
            }
        }
        vector<int> revAdj[V];
        transposeGraph(V, adj, revAdj);
        int res = 0;
        for(int i=0; i<V; i++)
            vis[i] = 0;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(!vis[t]){
                vis[t] = 1;
                dfs(t, revAdj, vis, st);
                res++;
            }
        }
        return res;
    }
};