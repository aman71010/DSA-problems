#include<bits\stdc++.h>
using namespace std;


// Best and Average case time complexity T-> O(n+m)
// Worst cases T-> O(n*m) 

//The average and best-case running time of the Rabin-Karp algorithm is O(n+m),
//but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs 
//when all characters of pattern and text are same as the hash values of all the 
//substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.

class Solution{
    public:
        bool isSame(string t, string p, int i){
            for(int j=0; j<p.size(); j++){
                if(t[i+j] != p[j])
                    return false;
            }
            return true;
        }

        vector<int> search(string pat, string txt){
            int m = pat.size();
            int n = txt.size();
            if(n<m) return {-1};
            vector<int> res;
            int d = 26, mh = 1;
            for(int i=0; i<m-1; i++)
                mh = (d*mh)%101;
            int pHash = 0, tHash = 0;
            for(int i=0; i<m; i++){
                pHash = (pHash*d + (pat[i]-'a'))%101;
                tHash = (tHash*d + (txt[i]-'a'))%101;
            }
            for(int i=0; i<=n-m; i++){
                if(pHash == tHash && isSame(txt, pat, i))
                    res.push_back(i);
                if(i<n-m){
                    tHash = ((tHash-(txt[i]-'a')*mh)*d + (txt[i+m]-'a'))%101;
                    if(tHash<0)
                        tHash += 101;
                } 
            }
            if(res.size()==0)
                res.push_back(-1);
            return res;
        }  
};