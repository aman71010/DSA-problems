
#include<bits\stdc++.h>
typedef unsigned long long ull;
using namespace std;

class Solution 
{
    public:
    // #define ull unsigned long long
	/* Function to get the nth ugly number*/

    //------------------------- t=O(nlog(n))  -----------------------
	ull getNthUglyNo(int n) {
	    set<ull> s;
        s.insert(1);
        n--;
        while (n--) {
            auto it = s.begin();
            ull x = *s.begin();
            s.erase(it);
            s.insert(x*2);
            s.insert(x*3);
            s.insert(x*5);
        }
        return *s.begin();
        
	}

    //------------------------- t=O(n) s=O(n) -----------------------
	ull getNthUglyNo(int n) {
	    ull ugly[n];
        int i2=0, i3=0, i5=0;
        ull nextMul2 = 2;
        ull nextMul3 = 3;
        ull nextMul5 = 5;
        ull nextUgly = 1;
        ugly[0] = nextUgly;
        for(int i=1; i<n; i++){
            nextUgly = min(nextMul2, min(nextMul3, nextMul5));
            ugly[i] = nextUgly;
            if(nextUgly == nextMul2){
                i2++;
                nextMul2 = ugly[i2]*2;
            }
            if(nextUgly == nextMul3){
                i3++;
                nextMul3 = ugly[i3]*3;
            }
            if(nextUgly == nextMul5){
                i5++;
                nextMul5 = ugly[i5]*5;
            }
        }
        return ugly[n-1];
	}
    
};