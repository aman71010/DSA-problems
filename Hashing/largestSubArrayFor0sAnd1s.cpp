#include<bits\stdc++.h>
typedef long long ll;
using namespace std;

class Solution 
{
    public:
    int maxLen(int arr[], int n)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum=0;
        int len=0;
        int endInd=-1;
        for(int i=0; i<n; i++){
            sum += arr[i]==0 ? -1: 0;
            if(mp.find(sum)!=mp.end()){
                if(len<i-mp[sum]){
                    len = i-mp[sum];
                    endInd = i;
                }
            }
            else
                mp[sum] = i;
        }
        if(endInd==-1) return -1;
        return len;
    }
};

int main(){
    return 0;
}