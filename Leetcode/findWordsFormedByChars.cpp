#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> m;
        for(char c: chars)
                m[c]++;
        for(int i=0; i<words.size(); i++){
            unordered_map<char, int> wm;
            bool cond = true;
            for(char c: words[i])
                wm[c]++;
            for(auto x: wm){
                if(m[x.first]>=x.second)
                    continue;
                else{
                    cond = false;
                    break;
                }
            }
            if(cond) ans+=words[i].length();
        }
        return ans;
    }
};