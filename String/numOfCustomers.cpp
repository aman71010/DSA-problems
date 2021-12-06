#include <bits/stdc++.h>
using namespace std;

int findCustomers(int n, string s){
    int m = s.length();
    int count = 0, ans = 0;
    bool seen[26] = {0};
    for(int i=0; i<m; i++){
        if(seen[s[i]-'A']){
            count--;
            seen[s[i]-'A'] = 0;
        }
        else{
            seen[s[i]-'A'] = 1;
            count++;
            if(count>n){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int t = 6;
    int arr[t] = {2, 3, 3, 1, 1, 3};
    string str[t] = {"ABBAJJKZKZ", "GACCBDDBAGEE", "GACCBGDDBAEE", "ABCBCA", "ABCBCADEED", "ABBCDEFGEFGCDIAI"};
    int i = 0;
    while(i<t){
        cout << findCustomers(arr[i], str[i])<< endl;
        i++;
    }
    
    return 0;
}