#include<bits\stdc++.h>
using namespace std;

class Solution{
  public:
    int SubsequenceLength (string s) {
        int start = 0, end = 0, maxLen = 0;
        int index[26];
        for(int i=0; i<26; i++)
            index[i] = -1;
        while(end<s.length()){
            if(index[s[end]-'a']==-1)
                index[s[end]-'a'] = end;
            else{
                start = max(start, index[s[end]-'a']+1);
                index[s[end]-'a'] = end;
            }
            if(end-start+1>maxLen)
                maxLen = end-start+1;
            end++;
        }
        return maxLen;
    }
};