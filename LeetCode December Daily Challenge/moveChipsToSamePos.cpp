#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // t-> O(n) s-> O(n)

    int minCostToMoveChips(vector<int>& position) {
        int e = 0, o = 0;
        for(int i=0; i<position.size(); i++){
            if(position[i]%2 == 0)
                e++;
            else
                o++;
        }
        if(e==0 || o==0)
            return 0;
        return min(e, o);
    }
};