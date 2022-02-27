#include<bits\stdc++.h>
using namespace std;


class Solution{
  public:
    string nextPalin(string s) { 
        int n =s.length();
        if (n <= 3) {
            return "-1";
        }
        int mid = n / 2 - 1;
        int i, j;
        for (i = mid - 1; i >= 0; i--)
            if (s[i] < s[i + 1])
                break;
        if (i < 0) {
             return "-1";
        }
        int smallest = i + 1;
        for (j = i + 2; j <= mid; j++)
            if (s[j] > s[i] && s[j] <= s[smallest])
                smallest = j;
        swap(s[i], s[smallest]);
        swap(s[n - i - 1], s[n - smallest - 1]);
        reverse(s, i + 1, mid);
        if (n % 2 == 0)
            reverse(s, mid + 1, n - i - 2);
        else
            reverse(s, mid + 2, n - i - 2);
        return s;
    }
    
    void reverse(string &s, int i, int j){
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};


