#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    // T-> O(n*k) S-> O(n)
    int catchThieves(char arr[], int n, int k) {
        int ans = 0;
        bool isPos[n];
        for(int i=0; i<n; i++){
            if(arr[i]=='P')
                isPos[i] = true;
            else
                isPos[i] = false;
        }
        for(int i=0; i<n; i++){
            if(arr[i]=='P'){
                int j=i-k;
                if(j<0) j=0;
                while(j<=i+k && j<n){
                    if(!isPos[j]){
                        ans++;
                        isPos[j] = true;
                        break;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};

class Solution{
    public:
    // T-> O(n) S-> O(n)
    int catchThieves(char arr[], int n, int k) {
        int ans = 0;
        vector<int> p;
        vector<int> t;
        for(int i=0; i<n; i++){
            if(arr[i]=='P')
                p.push_back(i);
            else
                t.push_back(i);
        }
        int i=0, j=0;
        while(i<p.size() && j<t.size()){
            if(abs(p[i]-t[j])<=k){
                ans++;
                i++;
                j++;
            }else if(p[i]<t[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};

class Solution{
    public:
    // T-> O(n) S-> O(1)
    int catchThieves(char arr[], int n, int k) {
        int ans = 0;
        int p = -1, t = -1;
        for(int i=0; i<n; i++){
            if(arr[i]=='P'){
                p = i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]=='T'){
                t = i;
                break;
            }
        }
        if(p == -1 || t == -1)
            return 0;
        int i=0, j=0;
        while(p<n && t<n){
            if(abs(p-t)<=k){
                ans++;
                p = p+1;
                while(p<n && arr[p]!='P')
                    p++;
                t = t+1;
                while(t<n && arr[t]!='T')
                    t++;
            }else if(p<t){
                p = p+1;
                while(p<n && arr[p]!='P')
                    p++;
            }
            else{
                t = t+1;
                while(t<n && arr[t]!='T')
                    t++;
            }
        }
        return ans;
    }
};