#include<bits\stdc++.h>
typedef long long ll;
using namespace std;

class Solution 
{
    public:
    //Function to count subarrays with sum equal to k.
    ll findSubarray(vector<ll> arr, int n, int k ) {
        ll ans = 0;
        ll sum = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        for(ll i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    return 0;
}