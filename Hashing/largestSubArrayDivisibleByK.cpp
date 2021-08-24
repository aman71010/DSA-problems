#include<bits\stdc++.h>
using namespace std;

class Solution 
{
     int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
        int sum = 0;
        int len = 0;
	    unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum += arr[i];
            int rem = (sum%k)>=0 ? (sum%k): (sum%k)+k;
            if(mp.find(rem)!=mp.end()){
                if(len<i-mp[rem])
                    len = i-mp[rem];
            }
            else{
                mp[rem] = i;
            }
        }
        return len;
	}
};

int main(){
    return 0;
}