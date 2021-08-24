#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    int longestUniqueSubsttr(string S){
        unordered_map<char, int> mp;
        int n = S.length();
        int l = 0, r = 0, ans = 0;
        while(r<n){
            if(mp.find(S[r])!=mp.end()){
                l = max(l, (mp[S[r]] + 1));
            }
            mp[S[r]] = r;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
        
    }

    //another solution
    int longestUniqueSubsttr(string S){
        vector<char> lastOccur(256, -1);
        int n = S.length();
        int l = 0, r = 0, ans = 0;
        while(r<n){
            l = max(l, lastOccur[S[r]-'a'] + 1);

            ans = max(ans, r-l+1);

            lastOccur[S[r]-'a'] = r;

            r++;
        }
        return ans;
        
    }

};

int main(){
    return 0;
}