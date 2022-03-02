#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    //T -> O(V+E)
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        bool visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(adj, visited, i, res);
            }
        }
        return res;
    }

    void dfs(vector<int> adj[], bool visited[], int i, vector<int> &res){
        visited[i] = true;
        res.push_back(i);
        for(int x: adj[i]){
            if(!visited[x])
                dfs(adj, visited, x, res);
        }
    }
};