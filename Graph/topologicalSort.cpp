#include<bits\stdc++.h>
using namespace std;

class Solution{
	public:
	//Function to return list containing vertices in Topological order.
    // BFS method 
    // T-> O(V+E)
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
	    int inDegree[V] = {0};
        for(int i=0; i<V; i++){
            for(int x: adj[i])
                inDegree[x]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++)
            if(!inDegree[i])
                q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int x: adj[u]){
                inDegree[x]--;
                if(inDegree[x]==0) 
                    q.push(x);
            }
        }
        return res;
	}
};


class Solution{
	public:
	//Function to return list containing vertices in Topological order.
    // DFS method 
    // T-> O(V+E)
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
        bool visited[V] = {0};
	    stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i])
                dfs(adj, visited, i, st);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
	}

    void dfs(vector<int> adj[], bool visited[], int s, stack<int> &st){
        visited[s] = 1;
        for(int x: adj[s]){
            if(!visited[x]){
                dfs(adj, visited, x, st);
            }
        }
        st.push(s);
    }
};