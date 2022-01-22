#include<bits\stdc++.h>
using namespace std;

class Solution{
public:
    //recurrsive
    int palindromicPartition(string str){
        int i=0, j=str.length()-1;
        return minPalindromeCut(str,i,j);
    }

    int minPalindromeCut(string &str, int i, int j){
        if(i==j || isPalindrome(str,i,j))
            return 0;
        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            int cuts = minPalindromeCut(str,i,k) + minPalindromeCut(str,k+1,j) + 1;
            if(ans>cuts)
                ans = cuts;
        }
        return ans;
    }

    bool isPalindrome(string &str, int i, int j){
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

class Solution{
public:
    // bottom up T-> O(n*3) s->O(n*2)
    int palindromicPartition(string str){
        int n = str.length();
        bool pal[n][n];
        int cuts[n][n];
        for(int g=0; g<n; g++){
            for(int i=0,j=g; j<n; i++,j++){
                if(g==0)
                    pal[i][j] = 1;
                else if(g==1)
                    pal[i][j] = str[i]==str[j];
                else
                    pal[i][j] = str[i]==str[j] && pal[i+1][j-1];
                if(pal[i][j])
                    cuts[i][j] = 0;
                else{
                    cuts[i][j] = INT_MAX;
                    for(int k=i; k<j; k++){
                        int cut = cuts[i][k] + cuts[k+1][j] + 1;
                        cuts[i][j] = min(cuts[i][j], cut);
                    }
                }
            }
        }
        return cuts[0][n-1];
    }
};