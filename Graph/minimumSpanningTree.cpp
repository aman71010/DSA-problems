#include<bits\stdc++.h>
using namespace std;

class DSU {
    int *parent;
    int *rank;
    public:
    DSU(int V){
        parent = new int[V];
        rank = new int[V];
        for(int i=0; i<V; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_( int s, int d) {
        int x = find(s);
        int y = find(d);
        if(x!=y){
            if(rank[x]>=rank[y]){
                parent[y] = x;
                rank[x] += rank[y];
            }
            else {
                parent[x] = y;
                rank[y] += rank[x];
            }
        }
    }

};


struct Edge {
    int edgeWt;
    int src;
    int des;
};


// krushkal's Algo
// T-> O(ElogV) + O(ElogE)
class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<Edge> edges;
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                Edge e;
                e.edgeWt = adj[i][j][1];
                e.src = i;
                e.des = adj[i][j][0];
                edges.push_back(e);
            }
        }
        sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b){return a.edgeWt<b.edgeWt;});
        int res = 0;
        int count = V-1;
        DSU obj(V);
        for(int i=0; i<edges.size(); i++){
            int x = obj.find(edges[i].src);
            int y = obj.find(edges[i].des);
            if(x!=y){
                obj.union_(x, y);
                res += edges[i].edgeWt;
                count--;
                if(count == 0)
                    break;
            }
        }
        return res;
    }
};