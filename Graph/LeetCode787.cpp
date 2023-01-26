#include<bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    int ans = INT_MAX;
	void dfs(int n, vector<pair<int,int>> adj[], vector<bool>& vis, int dst, int k, int node, int stops, int cost){
		if(vis[node])
			return;
		vis[node] = true;
		if(node == dst){
			ans = min(ans, cost);
            vis[node] = false;
			return;
		}
		if(stops >= k){
            vis[node] = false;
			return;
        }
		for(auto pr: adj[node]){
			if(!vis[pr.first]){
				dfs(n, adj, vis, dst, k, pr.first, stops+1, cost+pr.second);
			}
		}
		vis[node] = false;
	}

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
		for(int i=0; i<flights.size(); i++)
			adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
		vector<bool> vis(n,false);
		dfs(n, adj, vis, dst, k, src, -1, 0);
		return ans == INT_MAX ? -1: ans;
    }
};

// T-> O(N + E*K)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
		for(int i=0; i<flights.size(); i++)
			adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
		vector<int> dis(n, INT_MAX);
		queue<pair<int,int>> q;
		q.push({src,0});
		dis[src] = 0;
		int stops = -1;
		while(!q.empty() && stops<k){
			int s = q.size();
			while(s--){
				auto curr = q.front();
				q.pop();
				for(auto node: adj[curr.first]){
                    if(curr.second+node.second < dis[node.first]){
					    dis[node.first] = curr.second+node.second;
					    q.push({node.first, curr.second+node.second});
                    }
				}
			}
			stops++;
		}
		return dis[dst] == INT_MAX ? -1: dis[dst];
    }
};