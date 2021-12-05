#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m!=n)
            return false;
        unordered_map<char, char> map;
        unordered_set<char> st;
        for(int i=0; i<m; i++){
            if(map.find(s[i]) != map.end()){
                if(map[s[i]] != t[i])
                    return false;
            }
            else{
                if(st.find(t[i]) != st.end())
                    return false;
                else{
                    map[s[i]] = t[i];
                    st.insert(t[i]);
                }
            }
        }
        return true;     
    }
};