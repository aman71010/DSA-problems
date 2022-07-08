#include<bits\stdc++.h>
using namespace std;

//Number of each denomination of coins is only one.

class solution{
    public:

    int solve(int coins[], int amount, int idx){
        if(amount==0)
            return 0;
        if(idx<0)
            return INT_MAX;
        if(coins[idx]>amount)
            return solve(coins, amount, idx-1);
        else{
            int a = solve(coins, amount, idx-1);
            int b = solve(coins, amount-coins[idx], idx-1);
            b = (b == INT_MAX)? INT_MAX: b+1;
            return min(a,b);
        }
    }

    int MinCoins(int coins[], int amount, int n){
        int ans = solve(coins, amount, n-1);
        return ans == INT_MAX ? -1: ans;
    }

};

class solution{
    public:

    int MinCoins(int coins[], int A, int n){
        vector<vector<int>> dp(2, vector<int> (A+1));
        for(int j=0; j<=A; j++)
            dp[0][j] = INT_MAX;
        for(int i=1; i<=n; i++){
            dp[i%2][0] = 0;
            for(int j=1; j<=A; j++){
                if(coins[i-1]>j)
                    dp[i%2][j] = dp[(i-1)%2][j];
                else{
                    int a = dp[(i-1)%2][j];
                    int b = dp[(i-1)%2][j-coins[i-1]];
                    b = (b==INT_MAX)? b: b+1;
                    dp[i%2][j] = min(a, b);
                }
            }
        }
        return dp[n%2][A]==INT_MAX? -1: dp[n%2][A];
    }
};

int main(){
    solution obj;
    int coins[9] = {2, 3, 5, 6, 7, 12, 13, 14, 15};
    //int coins[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << obj.MinCoins(coins, 25, 8);
    return 0;
}



