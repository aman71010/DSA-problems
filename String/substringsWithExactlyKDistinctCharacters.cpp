#include<bits\stdc++.h>
using namespace std;


class Solution{
  public:
  
    int getSize(int freq[]){
        int ans = 0;
        for(int i=0; i<26; i++){
            if(freq[i]>0)
                ans++;
        }
        return ans;
    }
    
    long long int atMostKDistinct(string &s, int k){
        long long int res = 0;
        int left = 0;
        int freq[26] = {0};
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++;
            while(getSize(freq)>k){
                freq[s[left]-'a']--;
                left++;
            }
            res += (i-left+1);
        }
        return res;
    }

    long long int substrCount(string s, int k) {
    	return atMostKDistinct(s,k) - atMostKDistinct(s, k-1);
    }
};