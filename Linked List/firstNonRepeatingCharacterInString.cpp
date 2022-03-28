#include<bits\stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
            unordered_map<char, int> mp;
		    string res;
            for(int i=0; i<A.length(); i++){
                mp[A[i]]++;
                res += getFirstNonRepeating(mp, i, A);
            }
		    return res;
		}
        
        char getFirstNonRepeating(unordered_map<char, int> &mp, int i, string &A){
            char nr = '#';
            for(int j=0; j<=i; j++){
                if(mp[A[j]] == 1){
                    nr = A[j];
                    break;
                }
            }
            return nr;
        }
};

class Solution {
	public:
		string FirstNonRepeating(string A){
            queue<char> q;
		    string res = "";
            int freq[26] = {0};
            for(int i=0; i<A.length(); i++){
                q.push(A[i]);
                freq[A[i]-'a']++;
                while(!q.empty()){
                    if(freq[q.front()-'a'] > 1)
                        q.pop();
                    else{
                        res += q.front();
                        break;
                    }
                }
                if(q.empty()) res += '#';
            }
		    return res;
		}
};