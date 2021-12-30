#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T-> O(n^3) and S-> O(1)
    string longestPalindrome(string s) {
        int l = s.length();
        int ans = 1, start = 0;
        for(int i=0; i<l; i++){
            for(int j=i; j<l; j++){
                bool isPal = true;
                for(int k=0; k<(j-i+1)/2; k++){
                    if(s[i+k]!=s[j-k])
                        isPal = false;
                }
                if(isPal && (j-i+1)>ans){
                    start = i;
                    ans = j-i+1;
                } 
            }
        }
        return s.substr(start, ans);
    }

    // T-> O(n^2) and S-> O(n^2)
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 1, start = 0;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int g=0; g<n; g++){
            for(int i=0,j=g; j<n; i++, j++){
                if(g==0)
                    dp[i][j] = 1;
                else if(g==1)
                    dp[i][j] = s[i]==s[j];
                else
                    dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
                if(dp[i][j]){
                    start = i;
                    ans = g+1;
                }
            }
        } 
        return s.substr(start, ans);
    }

    // T-> O(n^2) and S-> O(1)
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 1, start = 0;
        int l, h;
        for(int i=1; i<n; i++){
            l=i-1;
            h=i;
            while(l>=0&&h<n && s[l]==s[h]){
                l--;
                h++;
            }
            l++;
            h--;
            if(s[l]==s[h] && h-l+1>ans){
                start = l;
                ans = h-l+1;
            }
            l=i-1;
            h=i+1;
            while(l>=0&&h<n && s[l]==s[h]){
                l--;
                h++;
            }
            l++;
            h--;
            if(s[l]==s[h] && h-l+1>ans){
                start = l;
                ans = h-l+1;
            }
        }
        return s.substr(start, ans);
    }
};