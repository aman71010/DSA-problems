#include<bits\stdc++.h>
using namespace std;


class Solution {
  public:
    string findSum(string X, string Y) {
        int n = X.length();
        int m = Y.length();
        string res = "";
        int c = 0, i=n-1, j=m-1;
        while(i>=0 || j>=0){
            int a = 0, b = 0;
            if(i>=0)
                a = X[i]-'0';
            if(j>=0)
                b = Y[j]-'0';
            int num = a+b+c;
            res = to_string(num%10)+ res;
            c = num/10;
            i--;
            j--;
        }
        if(c)
            res = to_string(c)+res;
        int l = res.length();
        if(l>1 && res[0]=='0'){
            int j = 0;
            while(j<l && res[j]=='0') j++;
            if(j == l)
                return "0";
            else
                return res.substr(j, l-j);
        }
        return res;
    }
};