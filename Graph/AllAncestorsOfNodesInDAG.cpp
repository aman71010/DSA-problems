#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>> res(n);
        for(int i=0; i<n; i++){
            bfs(adj, n, res, i);
        }
        return res;
    }

    void bfs(vector<int> adj[], int n, vector<vector<int>> &res, int parent){
        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(parent);
        visited[parent] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int x: adj[u]){
                if(visited[x]==0){
                    res[x].push_back(parent);
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }
};