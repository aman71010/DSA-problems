#include<bits\stdc++.h>
using namespace std;

class Solution{
public:

    bool findDuplicate(string s){
        int l = s.length();
        for(int i=0; i<l-1; i++){
            if(s[i]==s[i+1])
                return 1;
        }
        return 0;
    }

    string remove(string s){
        if(s.length()<=1)
            return s;
        while(findDuplicate(s)){
            int l = s.length();
            string temp = "";
            int i=0, j=1;
            while(i<l && j<l){
                if(s[i]!=s[j] && i+1 == j){
                    temp += s[i];
                    i++;
                    j++;
                } else if(s[i]!=s[j] && i+1 != j){
                    i = j;
                    j++;
                } else {
                    j++;
                }
            }
            if(s[l-1]!=s[l-2])
                temp += s[l-1];
            s = temp;
        }
        return s;
        
    }
};