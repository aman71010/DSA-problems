#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<char, int> m;
        int ans=INT_MAX;
        for(int i=0; i<str.length(); i++){
            if(m.find(str[i])==m.end()){
                m[str[i]] = i;
            }
        }
        for(int i=0; i<patt.length(); i++){
            if(m.find(patt[i])!=m.end()){
                if(m[patt[i]]<ans)
                    ans = m[patt[i]];
            }
        }
        return ans==INT_MAX ? -1: ans;
    }
};

int main(){
    return 0;
}