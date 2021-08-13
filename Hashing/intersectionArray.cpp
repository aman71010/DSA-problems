#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        if(n<m)
            NumberofElementsInIntersection(b,a,m,n);
        int ans = 0;
        unordered_map<int, bool> mp;
        for(int i=0; i<m; i++){
            mp[b[i]] = true;
        }
        for(int i=0; i<n; i++){
            if(mp[a[i]]){
                ans++;
                mp[a[i]]=false;
            }
                
        }
        return ans;
    }
};

int main(){
    return 0;
}