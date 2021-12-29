#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int getValue(char c){
        if(c=='I')
            return 1;
        if(c=='V')
            return 5;
        if(c=='X')
            return 10;
        if(c=='L')
            return 50;
        if(c=='C')
            return 100;
        if(c=='D')
            return 500;
        if(c=='M')
            return 1000;
        return -1;
    }

    int romanToInt(string s) {
        int l = s.length();
        int ans = 0;
        for(int i=0; i<l; ){
            int f = getValue(s[i]);
            int se = i+1<l ? getValue(s[i+1]): 0;
            if(i+1<l && se > f){
                ans += (se-f);
                i = i+2;
            }
            else{
                ans += f;
                i++;
            }
        }
        return ans;
    }
};