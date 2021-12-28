#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        int r1 = 0, r2 = 0, i = 0, j = 0;
        while(i<n1 || j<n2){
            r1 = 0;
            r2 = 0;
            while(i<n1 && version1[i]!='.')
                r1 = r1*10 + version1[i++]-'0';
            i++;
            while(j<n2 && version2[j]!='.')
                r2 = r2*10 + version2[j++]-'0';
            j++;
            if(r1<r2)
                return -1;
            if(r1>r2)
                return 1;
            else
                continue;
        }
        return 0;
    }
};