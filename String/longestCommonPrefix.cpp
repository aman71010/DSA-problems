#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            ans = getLCP(ans, strs[i]);
        }
        return ans;
    }

    string getLCP(string &a, string &b){
        int i=0, j=0;
        string res = "";
        while(i<a.length() && j<b.length()){
            if(a[i]==b[j])
                res += a[i];
            i++;
            j++;
        }
        return res;
    }

    //--------efficient---------------------------

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int m = getMinLength(strs);
        string ans = "";
        for(int i=0; i<m; i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[j-1][i]!=strs[j][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }

    int getMinLength(vector<string>& strs){
        int minm = strs[0].length();
        for(int i=1; i<strs.size(); i++){
            if(strs[i].length()<minm)
                minm = strs[i].length();
        }
        return minm;
    }
};