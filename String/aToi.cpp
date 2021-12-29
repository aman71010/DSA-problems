#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool pos = true;
        long long int ans = 0;
        int i=0, l=s.length();
        while(i<l && s[i]==' ')
            i++;
        if(s[i]=='-')
            pos = false;
        if(s[i]=='-' || s[i]=='+')
            i++;
        while(i<l && ans<INT_MAX){
            if(s[i]<='9' && s[i]>='0'){
                ans = ans*10 + (s[i]-'0');
                i++;
            }
            else break;
        }
        if(!pos)
            ans = -1*ans;
        if(ans>INT_MAX)
            return INT_MAX;
        else if(ans<INT_MIN)
            return INT_MIN;
        return (int)ans;
    }
};