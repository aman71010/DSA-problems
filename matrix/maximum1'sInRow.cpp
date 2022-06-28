#include<bits\stdc++.h>
using namespace std;


// T->O(n^m) S->O(1)
// T->O(nlogm) S->O(1)


class Solution{
    public:
        // T->O(n+m) S->O(1)
        int maxOnes(vector<vector<int>> &mat, int n, int m){
            int ans = -1, max1 = INT_MIN;
            int j = m-1;
            for(int i=0; i<n; i++){
                if(mat[i][j] == 0) continue;
                while(j>=0 && mat[i][j])
                    j--;
                if(j == -1)
                    return i;
                int temp = m-(j+1);
                if(max1 < temp){
                    max1 = temp;
                    ans = i;
                }
            }
            return ans;
        }
};