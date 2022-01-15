#include<bits\stdc++.h>
using namespace std;

void stockBuySell(int price[], int n) {
    int i = 0, buy, sell;
    bool isProfit = false;
    while(i<n){
        while(i+1<n && price[i]>=price[i+1])
            i++;
        if(i==n-1)
            break;
        buy = i;
        i++;
        while(i<n && price[i]>=price[i-1])
            i++;
        sell = i-1;
        cout << "(" << buy << " " << sell << ") ";
        isProfit = true;
    }
    if(!isProfit) cout << "No Profit";
    cout << endl;
}