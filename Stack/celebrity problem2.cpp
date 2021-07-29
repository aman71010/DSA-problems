#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //Using two pointer solution T->O(n)  S->O(1)
        int i=0, j=n-1;
        while(i<j){
            if(M[i][j]) i++;
            else j--;
        }
        int c = i;
        for(int j=0; j<n; j++){
            if(j!=c && (M[c][j]==1 || M[j][c]==0))
                return -1;
        }
        return c;
    }
    
};

int main(){
    return 0;
}