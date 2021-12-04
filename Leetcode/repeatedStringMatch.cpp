#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    //---------------------------------------------------------------------------------------------------------------
    //t-> O(n*m) s-> O(1)
    bool checkSubstring(string s, string B){
        int n = s.length(), m = B.length();
        for(int i=0; i<=n-m; i++){
            int j;
            for(j=0; j<m; j++){
                if(s[i+j]!=B[j])
                    break;
            }
            if(j==m) return true;
        }
        return false;
    }
    
    //---------------------------------------------------------------------------------------------------------------
    bool patternMatch(string B, string s, int i){
        for(int j=0; j<B.length(); j++){
            if(B[j]!=s[i+j])
                return false;
        }
        return true;
    }

    bool checkSubstring2(string s, string B){
        int n = s.length(), m = B.length();
        long long int BHash = 0, subHash = 0;
        for(int i=0; i<m; i++){
            BHash += (B[i]-'a'+1);
            subHash += (s[i]-'a'+1);
        }
        if(BHash==subHash && patternMatch(B, s, 0))
            return true;
        for(int i=1; i<=n-m; i++){
            subHash -= (s[i-1]-'a'+1);
            subHash += (s[i+m-1]-'a'+1);
            if(BHash==subHash && patternMatch(B, s, i))
                return true;
        }
        return false;
    }

    int repeatedStringMatch(string A, string B) {
        string s = A;
        int ans = 1;
        while(s.length()<B.length()){
            s+=A;
            ans++;
        }
        if(checkSubstring2(s, B))
            return ans;
        if(checkSubstring2(s+A, B))
            return ans+1;
        return -1;
    }

};