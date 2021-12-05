#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive approach
    string longestPrefix(string s) {
        int m = s.length();
        if(m==1)
            return "";
        string res = "";
        int i=0, j=1, k=1;

        while(i<m && j<m){
            if(s[i]==s[j]){
                res += s[i];
                i++;
                j++;
            }
            else{
                i=0;
                j=k+1;
                res="";
            }
        }
        return res;
    }
    // T- O(n) s(n)
    string longestPrefix(string s) {
        int m = s.length();
        int lps[m];
        int len = 0, i = 1;
        lps[0] = 0;
        while(i<m){
            if(s[len]==s[i]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(m-lps[m-1], lps[m-1]);
    }
};