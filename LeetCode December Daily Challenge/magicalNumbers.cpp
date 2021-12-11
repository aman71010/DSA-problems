#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long int mod = 1e9+7;
        long long int lcm = (a*b)/gcd(a, b);
        long long int l = min(a, b), r = n*1LL*min(a, b), mid, pos, ans;
        while(l<=r){
            mid = l + (r-l)/2;
            pos = mid/a + mid/b - mid/lcm;
            if(pos<n)
                l = mid+1;
            else{
                ans = mid%mod;
                r = mid-1;
            }
        }
        return ans;
    }
};