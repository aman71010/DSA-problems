#include<bits\stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //T -> O(V+E)
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(checkCyle(adj, visited, i))
                    return true;
            }
        }
        return false;
    }

    bool checkCyle(vector<int> adj[], bool visited[], int s){
        queue<pair<int, int>> q;
        q.push({s, -1});
        visited[s] = true;
        while(!q.empty()){
            int u = q.front().first;
            int p = q.front().second;
            q.pop();
            
            for(int x: adj[u]){
                if(!visited[x]){
                    q.push({x,u});
                    visited[x] = true;
                } else if(x!=p)
                    return true;
            }
        }
        return false;
    }
};


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //T -> O(V+E)
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(checkCyle(adj, visited, i, -1))
                    return true;
            }
        }
        return false;
    }

    bool checkCyle(vector<int> adj[], bool visited[], int i, int p){
        visited[i] = true;
        for(int x: adj[i]){
            if(!visited[x]){
                if(checkCyle(adj, visited, x, i))
                    return true;
            } else if(x != p)
                return true;
        }
        return false;
    }
};