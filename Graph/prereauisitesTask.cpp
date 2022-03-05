#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        return !isCyclic(N, adj);
	}

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