#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool isDigit(char c){
        return (c>=48 && c<=57);
    }

    void permute(vector<string>& res, string& s, int l, int r){
        if(l==r+1){
            res.push_back(s);
            return;
        }
        else {
            for(int i=l; i<=r; i++){
                
                if(isDigit(s[i]) && i==r) {
                    res.push_back(s);
                    return;
                }
                else if(!isDigit(s[i])){
                    permute(res, s, l+1, r);
                    s[i] = toupper(s[i]);
                    permute(res, s, l+1, r);
                    s[i] = tolower(s[i]);
                }   
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        permute(res, s, 0, s.length()-1);
        return res;
    }
};