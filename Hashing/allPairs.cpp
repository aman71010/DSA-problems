#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int, int>> v;
        unordered_map<int, int> mp;
        for(int i=0; i<N; i++){
            if(mp.find(A[i])==mp.end())
                mp[A[i]] = 0;
            else
                mp[A[i]]++;
        } 

        for(int i=0; i<M; i++){
            if(mp.find(X-B[i])!=mp.end()){
                v.push_back({B[i], X-B[i]});
            }
        }
        return v;
    }
};

int main(){
    return 0;
}