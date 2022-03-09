#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    queue<pair<int,int>> q;
        vector<int> colors(V, -1);
        for(int i=0; i<V; i++){
            if(colors[i]==-1){
                colors[i] = 0;
                q.push({i,0});
                while(!q.empty()){
                    int u = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int v: adj[u]){
                        if(colors[v]==c) return false;
                        if(colors[v]==-1){
                            colors[v] = c==0 ? 1: 0;
                            q.push({v,colors[v]});
                        }
                    }
                }
            }
        }
        return true;
	}
};