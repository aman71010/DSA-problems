#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string ans = "11";
        for(int i=3; i<=n; i++){
            string prev = ans;
            ans = "";
            int len = prev.length(), count = 1;
            for(int j=0; j<len; j++){
                if(j+1<len && prev[j]==prev[j+1])
                    count++;
                else{
                    ans+= (count+'0');
                    ans+= prev[j];
                    count = 1;
                }
            }
        }
        return ans;
    }
};