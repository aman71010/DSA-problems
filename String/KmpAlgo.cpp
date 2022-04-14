#include<bits\stdc++.h>
using namespace std;

// T-> O(n) S-> O(n)
class Solution{
    public:
        void constructLps(string &pat, string &txt, int lps[], int m){
            lps[0] = 0;
            int len = 0, i=1;
            while(i<m){
                if(pat[len]==pat[i]){
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if(len != 0)
                        len = lps[len-1];
                    else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        vector<int> search(string pat, string txt){
            int n = txt.size();
            int m = pat.size();
            vector<int> res;
            if(n<m) return res;
            int lps[m];
            constructLps(pat, txt, lps, m);
            int i=0, j=0;
            while(i<n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                if(j == m){
                    res.push_back(i-m + 1);
                    j = lps[j-1];
                }
                else{
                    if(i<n && txt[i] != pat[j]){
                        if(j != 0)
                            j = lps[j-1];
                        else
                            i++;
                    }
                }
            }
            return res;
        }
};