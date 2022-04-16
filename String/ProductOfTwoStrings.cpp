#include<bits\stdc++.h>
using namespace std;


class Solution{
  public:
    string multiplyStrings(string s1, string s2) {
        if(s1 == "0" || s2 == "0")
            return "0";
        int n = s1.length(), m = s2.length();
        bool isNeg = false;
        if( s1[0]=='-' ^ s2[0]=='-')
            isNeg = true;
        if(s1[0] == '-')
            s1 = s1.substr(1,n-1);
        if(s2[0] == '-')
            s2 = s2.substr(1,m-1);
        string ans = multiplyStringsUtil(s1, s2);
        return isNeg? "-"+ans: ans;
    }

    string multiplyStringsUtil(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        vector<int> res(n+m, 0);
        int p1 = 0, p2 = 0, c = 0;
        for(int i=m-1; i>=0; i--){
            int m1 = s2[i]-'0';
            c = 0, p2 = 0;
            for(int j=n-1; j>=0; j--){
                int n1 = s1[j]-'0';
                int num = n1*m1 + c + res[p1+p2];
                res[p1+p2] = num%10;
                p2++;
                c = num/10;
            }
            if(c)
                res[p1+p2] += c;
            p1++;
        }
        int i = res.size()-1;
        while(i>=0 && res[i]==0)
            i--;
        if(i==-1) return "0";
        string ans = "";
        while(i>=0){
            ans += res[i]+'0';
            i--;
        }
        return ans;
    }
};