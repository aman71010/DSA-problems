#include<bits\stdc++.h>
using namespace std;

class Solution{
	public:
	string fractionToDecimal(int num, int den) {
	    if(num==0)
            return "0";
        string res = "";
        res += ((num<0)^(den<0)) ? "-": "";
        long long int n = abs(num);
        long long int d = abs(den);
        res += to_string(n/d);
        long long int rem = n%d;
        if(rem == 0) return res;
        res += ".";
        unordered_map<int, int> mp;
        bool isRepet = false;
        int openParInd;
        while(rem > 0 && !isRepet){
            if(mp.find(rem) != mp.end()){
                isRepet = true;
                openParInd = mp[rem];
                break;
            } else
                mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem/d);
            rem = rem%d;
        }
        if(isRepet){
            res += ")";
            res.insert(openParInd, "(");
        }
        return res;
            
	}
};