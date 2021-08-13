#include<bits\stdc++.h>
typedef long long ll;
using namespace std;

class Solution 
{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        ll ans = 0;
        ll sum = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        for(ll i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum)!=mp.end()){
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    return 0;
}