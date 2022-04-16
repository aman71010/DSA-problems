#include<bits\stdc++.h>
using namespace std;

class Solution{
  public:
    // T-> O(n^2) S-> O(k)
    long long int substrCount(string s, int k) {
    	int n = s.length();
        long long int ans = 0;
        for(int i=0; i<=n-k; i++){
            int j=i;
            unordered_set<char> st;
            
            while(j<n && st.size()<=k){
                st.insert(s[j]);
                j++;
                if(st.size()==k)
                    ans++;
            }
        }
        return ans;
    }
};

class Solution{
  public:
    long long int atMostKDistinct(string &s, int k){
        long long int res = 0;
        int left = 0;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0)
                    mp.erase(s[left]);
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