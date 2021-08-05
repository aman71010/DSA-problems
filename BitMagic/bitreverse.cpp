#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    long long reversedBits(long long n) {
        long long res = 0;
        for(int i=0; i<32; i++){
            long long lsb = n&1;
            long long reverseLsb = lsb<<(31-i);
            res = res|reverseLsb;
            n = n>>1;
        }
        return res;
    }
};

int main(){
    return 0;
}