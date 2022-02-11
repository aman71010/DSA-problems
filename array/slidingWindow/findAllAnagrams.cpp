#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length(), n = s.length();
        vector<int> req(26, 0);
        vector<int> window(26, 0);
        vector<int> res;
        for(char x: p)
            req[x-'a']++;
        int start = 0, end = 0;
        while(end<n){
            window[s[end]-'a']++;
            if(end-start+1>m)
                window[s[start++]-'a']--;
            if(req==window){
                res.push_back(start);
            }
            end++;
        }
        return res;
    }
};