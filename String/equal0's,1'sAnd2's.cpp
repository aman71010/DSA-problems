#include<bits\stdc++.h>  
using namespace std;

// T-> O(n^2) S-> O(1) naive

// T-> O(nlongn) S-> O(n)
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        long long res = 0;
        int l = str.length();
        int countZeros = 0, countOnes = 0, countTwos = 0;
        map<pair<int,int>, int> mp;
        mp[{0,0}] = 1;
        for(int i=0; i<l;  i++){
            if(str[i]=='0') countZeros++;
            else if(str[i]=='1') countOnes++;
            else countTwos++;
            int a = countOnes-countZeros;
            int b = countTwos-countZeros;
            res += mp[{a,b}];
            mp[{a,b}]++;
        }
        return res;
    }
};