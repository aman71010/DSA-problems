#include<bits\stdc++.h>
using namespace std;

// T-> O(n^2) s-> O(26)
//naive approach

// T-> O(n*logn) s-> O(26) ignoring recurrsive call stack
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringUtility(s, k, 0, s.length());
    }

    int longestSubstringUtility(string &s, int k, int start, int end){
        int freq[26] = {0};
        for(int i=start; i<end; i++)
            freq[s[i]-'a']++;
        int left, right;
        for(int i=start; i<end; i++){
            if(freq[s[i]-'a'] < k){
                left = longestSubstringUtility(s, k, start, i);
                right = longestSubstringUtility(s, k, i+1, end);
                return max(left, right);
            }
        }
        return end-start;
    }
};

