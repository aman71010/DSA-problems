#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // t-> O(n) s-> O(1)

    int maxProduct(vector<int>& nums) {
        int maxEndHere = nums[0], minEndHere = nums[0], ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            int temp = max(max(nums[0], nums[0]+maxEndHere), nums[0]+minEndHere);
            minEndHere = min(min(nums[0], nums[0]+maxEndHere), nums[0]+minEndHere);
            maxEndHere = temp;
            ans = max(ans, maxEndHere);
        }
        return ans;
    }
};