#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
     vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map <int, int > mp;
        vector <int> v;
        int i;
        for(i=0; i<k; i++){
            if(mp.find(A[i])==mp.end())
                mp[A[i]] = 1;
            else
                mp[A[i]]++;
        }
        v.push_back(mp.size());

        for(int j=i; j<n; j++){
            mp[A[j-k]]--;
            if(mp[A[j-k]]==0)
                mp.erase(A[j-k]);
            if(mp.find(A[j])==mp.end())
                mp[A[j]] = 1;
            else
                mp[A[j]]++;
            v.push_back(mp.size());
        }
        
    }
};

int main(){
    return 0;
}