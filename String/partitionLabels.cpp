#include<bits\stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int lastOcurr[26] = {0};
        for(int i=0; i<s.length(); i++)
            lastOcurr[s[i]-'a'] = i;
        int partsLen = INT_MIN, start = 0;
        for(int i=0; i<s.length(); i++){
            partsLen = max(partsLen, lastOcurr[s[i]-'a']);
            if(partsLen<=i){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};