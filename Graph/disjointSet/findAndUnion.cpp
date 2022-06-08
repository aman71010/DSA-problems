#include<bits\stdc++.h>
using namespace std;

//T-> O(logN)
class Solution{
    public:
    int find(int x, int par[]){
        if(par[x]==x) return x;
        par[x] = find(par[x], par);
        return par[x];
    }

    void union_( int a, int b, int par[], int rank[]) {
        int x = find(a, par);
        int y = find(b, par);
        if(x!=y){
            if(rank[x]>rank[y])
                par[y] = x;
            else if(rank[x]<rank[y])
                par[x] = y;
            else {
                par[y] = x;
                rank[x]++;
            }
        }
    }

    bool isConnected(int x,int y, int par[], int rank[]){
        return find(x, par) == find(y, par);
    }
};