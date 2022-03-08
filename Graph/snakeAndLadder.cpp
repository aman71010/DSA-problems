#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    int minThrow(int N, int arr[]){
        int sz = 30;
        vector<int> moves(sz+1, -1);
        for(int i=0; i<2*N-1; i += 2)
            moves[arr[i]] = arr[i+1];
        queue<pair<int,int>> q;
        vector<bool> visited(sz+1, false);
        q.push({1,0});
        visited[1] = true;
        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            int v = pr.first, minThrow = pr.second;
            if(v==sz) return minThrow;
            for(int j=v+1; j<=v+6 && j<=sz; j++){
                if(visited[j]==false){
                    int u;
                    visited[j] = true;
                    if(moves[j]!=-1)
                        u = moves[j];
                    else
                        u = j;
                    q.push({u,minThrow+1});
                }
            }
        }
        return -1;
    }
};