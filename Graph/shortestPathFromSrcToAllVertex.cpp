#include<bits\stdc++.h>
using namespace std;

typedef pair<int, int> iPair;


//Dijkstra's Algo
// T-> O(ElogV)
class Solution{
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dis(V, INT_MAX); 
        dis[S]= 0;
        priority_queue<iPair, vector<iPair>, greater<iPair>> minHeap;
        minHeap.push({0,S});
        while(!minHeap.empty()){
            int u = minHeap.top().second;
            int sd = minHeap.top().first;
            minHeap.pop();
            for(auto node: adj[u]){
                int v = node[0];
                int weight = node[1];
                if(dis[v] > sd+weight){
                    dis[v] = sd+weight;
                    minHeap.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};