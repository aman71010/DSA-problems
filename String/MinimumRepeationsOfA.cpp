#include<bits\stdc++.h> 
using namespace std;

class Solution {
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

    bool search(string pat, string txt){
        int n = txt.size();
        int m = pat.size();
        if(n<m) return false;
        int lps[m];
        constructLps(pat, txt, lps, m);
        int i=0, j=0;
        while(i<n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == m){
                return true;
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
        return false;
    }

int minRepeats(string A, string B) {
    string s = A;
    int ans = 1;
    while(s.length()<B.length()){
        s += A;
        ans++;
    }
    if(search(B,s))
        return ans;
    if(search(B,s+A))
        return ans+1;
    return -1;

}
};