#include<bits\stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in an directed graph.
    //T -> O(V+E)
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V] = {0};
        bool recurCallStack[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(checkCyle(adj, visited, recurCallStack, i))
                    return true;
            }
        }
        return false;
    }

    bool checkCyle(vector<int> adj[], bool visited[], bool recurCallStack[], int i){
        visited[i] = true;
        recurCallStack[i] = true;
        for(int x: adj[i]){
            if(!visited[x]){
                if(checkCyle(adj, visited, recurCallStack, x))
                    return true;
            } else if(recurCallStack[x])
                return true;
        }
        recurCallStack[i] = false;
        return false;
    }
};

class Solution {
  public:
    // Function to detect cycle in an directed graph.
    //T -> O(V+E)
    bool isCyclic(int V, vector<int> adj[]) {
        int inDegree[V] = {0};
        for(int i=0; i<V; i++)
            for(int x: adj[i])
                inDegree[x]++;
        int count = 0;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int x: adj[u]){
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        if(count==V)
            return false;
        return true;
    }
};