#include<bits\stdc++.h>
using namespace std;


class Solution{
	public:
	int minSteps(int m, int n, int d){
	    if(m>n)
            minSteps(n, m, d);
	    if(d>n) return -1;
        map<pair<int,int>,int> mp;
        int count1, count2;
        count1 = 1;
        int c1 = m, c2 = 0;
        mp[{c1,c2}]++;
        while(c1!=d && c2!=d){
            int remain = n-c2;
            if(remain>=c1){
                c2+=c1;
                c1=0;
                count1++;
            } else {
                c2+=remain;
                c1-=remain;
                count1++;
            }
            if(c1==d || c2==d)
                break;
            if(c1==0){
                c1 = m;
                count1++;
            }
            if(c2==n){
                c2 = 0;
                count1++;
            }
            if(mp.find({c1,c2})!=mp.end()){
                count1 = -1;
                break;
            }
        }
        count2 = 1;
        c1 = 0, c2 = n;
        mp[{c1,c2}]++;
        while(c1!=d && c2!=d){
            int remain = m-c1;
            if(remain>=c2){
                c1+=c2;
                c2=0;
                count2++;
            } else {
                c1+=remain;
                c2-=remain;
                count2++;
            }
            if(c1==d || c2==d)
                break;
            if(c1==m){
                c1 = 0;
                count2++;
            }
            if(c2==0){
                c2 = n;
                count2++;
            }
            if(mp.find({c1,c2})!=mp.end()){
                count2 = -1;
                break;
            }
        }
        if(count1==-1 && count2==-1)
            return -1;
        else if(count1 == -1)
            return count2;
        else if(count2 == -1)
            return count1;
        return min(count1, count2);
	}
};