#include<bits\stdc++.h>
using namespace std;

//The structure to use is as follows
struct val{
	int first;
	int second;
};

//-------------------------------dp bottom up---------------------------------
bool compare(val a, val b){
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n){
    sort(p, p+n, compare);
    int mcl[n];
    for(int i=0; i<n; i++)
        mcl[i] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(p[i].first > p[j].second && mcl[i]<mcl[j]+1){
                    mcl[i] = mcl[j]+1;
            }
        }
    }
    int ans = mcl[0];
    for(int i=1; i<n; i++){
        if(mcl[i]>ans)
            ans = mcl[i];
    }
    return ans;
}

//-------------------------------Greedy approach---------------------------------
bool compare(val a, val b){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n){
    sort(p, p+n, compare);
    int ans = 1;
    int i = 0, j;
    for(int j=1; j<n; j++){
        if(p[j].first > p[i].second){
            ans++;
            i=j;
        }
    }
    return ans;
}