#include <bits/stdc++.h>
using namespace std;

int minimumOperation(string s, string t){
    int m = s.length(), n = t.length();
    if(m!=n)
        return -1;
    int count[26] = {0};
    for(int i=0; i<m; i++){
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(count[i])
            return -1;   
    }
    int ans = 0;
    for(int i=n-1, j=n-1; i>=0; ){
        while(i>=0 && s[i]!=t[j]){
            i--;
            ans++;
        }
        if(i>=0){
            i--;
            j--;
        }
    }
    return ans;
}

int main(){
    string s = "eacbd", t = "eabcd";
    cout << minimumOperation(s, t);
    return 0;
}