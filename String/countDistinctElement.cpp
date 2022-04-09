#include<bits\stdc++.h>  
using namespace std;

// T-> O(n) S-> O(k)

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        int i=0, n = s.length(), res = 0;
        unordered_map<char, int> mp;
        for( ; i<k; i++)
            mp[s[i]]++;
        if(mp.size() == k-1)
            res++;
        for( ; i<n; i++){
            mp[s[i]]++;
            mp[s[i-k]]--;
            if(mp[s[i-k]] == 0) mp.erase(s[i-k]);
            if(mp.size() == k-1)
                res++;
        }
        return res;
    }
};

