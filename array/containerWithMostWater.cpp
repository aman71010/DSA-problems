#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, h = height.size();
        int maxA = 0, currA = 0;
        while(l<h){
            currA = (h-l)*min(height[l], height[h]);
            if(currA>maxA)
                maxA = currA;
            if(height[l]<=height[h])
                l++;
            else
                h--;
        }
        return maxA;
    }
};