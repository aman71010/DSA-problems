#include<bits\stdc++.h>
using namespace std;

// naive approach
// T-> O(V*(V+E)) S-> O(V)

// T-> O(V+E) S-> O(V)
class Solution {
    public:
	int findMotherVertex(int V, vector<int>adj[]){
	    int lastFV;
        vector<bool> vis(V, 0);
        for(int i=0; i<V; i++){
            if(vis[i] == false){
                dfs(adj, vis, i);
                lastFV = i;
            }
        }
        for(int i=0; i<V; i++)
            vis[i] = 0;
        dfs(adj, vis, lastFV);
        for(int i=0; i<V; i++){
            if(vis[i] == false)
                return -1;
        }
        return lastFV;
	}

    void dfs(vector<int> adj[], vector<bool> &vis, int s){
        vis[s] = 1;
        for(int v: adj[s]){
            if(!vis[v])
                dfs(adj, vis, v);
        }
    }

};