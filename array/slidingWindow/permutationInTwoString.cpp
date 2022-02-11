#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if(m>n) return false;
        vector<int> req(26, 0);
        vector<int> window(26, 0);
        for(char x: s1)
            req[x-'a']++;
        int start = 0, end = 0;
        while(end<n){
            window[s2[end]-'a']++;
            if(end-start+1>m){
                window[s2[start]-'a']--;
                start++;
            }
            if(req==window)
                return true;
            end++;
        }
        return false;
    }
};