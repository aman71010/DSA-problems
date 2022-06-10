#include<bits\stdc++.h>
using namespace std;


// T-> O(V+E)
class Solution{
	public:

    void dfs(int u, vector<int> adj[], vector<bool>& vis, int c, int d){
        vis[u] = 1;
        for(int v: adj[u]){
            if(!((c == u || d == u) && (c == v || d == v)) && !vis[v])
                dfs(v, adj, vis, c, d);
        }
    }


    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<bool> vis(V, false);
        dfs(c, adj, vis, c, d);
        return vis[d]==false;
    }
};
