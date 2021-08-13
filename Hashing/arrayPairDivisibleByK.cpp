#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() & 1) return false;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int rem = ((nums[i]%k)+k)%k;
            mp[rem]++;
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            int rem = (*it).first;
            int freq = (*it).second;
            if(rem==0){
                if(freq&1) return false;
            }
            else if(freq!=mp[k-rem]) return false;
        }
        return true;
    }

    //Another solution

    bool canPair(vector<int> nums, int k) {
        if(nums.size() & 1) return false;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int rem = ((nums[i]%k)+k)%k;
            mp[rem]++;
        }
        for(int i=0; i<nums.size(); i++){
            int rem = ((nums[i]%k)+k)%k;
            if(rem==0){
                if(mp[rem]&1) return false;
            }
            else if(mp[rem]!=mp[k-rem]) return false;
        }
        return true;
    }
};

int main(){
    return 0;
}