#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // T-> O(V+E)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        bool visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bfs(adj, visited, i, res);
            }
        }
        return res;
    }

    void bfs(vector<int> adj[], bool visited[], int s, vector<int> &res){
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int x: adj[u]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};