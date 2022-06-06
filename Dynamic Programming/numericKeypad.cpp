#include<bits\stdc++.h>
using namespace std;


// dfs (got TLE)
class Solution{
	public:

    bool isValidKey(int i, int j){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j==0) || (i==3 && j==2))
            return false;
        return true;
    }

	long long getCount(int n){
		if(n<=0) return 0;
        if(n==1) return 10;
        long long ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(isValidKey(i,j))
                    ans += dfs(i, j, n);
            }
        }
        return ans;
	}

    int dfs(int i, int j, int n){
        if(n==1)
            return 1;
        long long count = 0;
        int dx[5] = {0, 0, -1, 0, 1};
        int dy[5] = {0, -1, 0, 1, 0};
        for(int d=0; d<5; d++){
            int r = i+dx[d];
            int c = j+dy[d];
            if(isValidKey(r,c))
                count += dfs(r, c, n-1);
        }
        return count;
    }
};

// dfs + memoization
class Solution{
	public:

    long long getCount(int n){
		if(n<=0) return 0;
        if(n==1) return 10;
        vector<vector<char>> keypad(4);
        keypad[0] = {'1', '2', '3'};
        keypad[1] = {'4', '5', '6'};
        keypad[2] = {'7', '8', '9'};
        keypad[3] = {'*', '0', '#'};
        vector<vector<long long>> dp(10, vector<long long>(n, -1));
        long long ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(isValidKey(i,j))
                    ans += dfs(keypad, dp, i, j, n);
            }
        }
        return ans;
	}
	
	bool isValidKey(int i, int j){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j==0) || (i==3 && j==2))
            return false;
        return true;
    }

    long long dfs(vector<vector<char>> &keypad, vector<vector<long long>> &dp, int i, int j, int n){
        if(dp[keypad[i][j]-'0'][n-1] != -1)
            return dp[keypad[i][j]-'0'][n-1];
        if(n==1){
            dp[keypad[i][j]-'0'][n-1] = 1;
            return 1;
        }
        long long count = 0;
        int dx[5] = {0, 0, -1, 0, 1};
        int dy[5] = {0, -1, 0, 1, 0};
        for(int d=0; d<5; d++){
            int r = i+dx[d];
            int c = j+dy[d];
            if(isValidKey(r,c))
                count += dfs(keypad, dp, r, c, n-1);
        }
        dp[keypad[i][j]-'0'][n-1] = count;
        return count;
    }

};

// bottom up approach
// T-> O(n) and S-> O(n*10)
class Solution{
	public:

    long long getCount(int n){
		if(n<=0) return 0;
        if(n==1) return 10;
        vector<vector<char>> keypad(4);
        keypad[0] = {'1', '2', '3'};
        keypad[1] = {'4', '5', '6'};
        keypad[2] = {'7', '8', '9'};
        keypad[3] = {'*', '0', '#'};
        vector<vector<long long>> dp(10, vector<long long>(n+1));
        for(int i=0; i<=9; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        int dx[5] = {0, 0, -1, 0, 1};
        int dy[5] = {0, -1, 0, 1, 0};
        for(int k=2; k<=n; k++){
            for(int i=0; i<4; i++){
                for(int j=0; j<3; j++){
                    if(keypad[i][j] != '*' && keypad[i][j] != '#'){
                        dp[keypad[i][j]-'0'][k] = 0;
                        for(int d=0; d<5; d++){
                            int r = i+dx[d];
                            int c = j+dy[d];
                            if(isValidKey(r,c))
                                dp[keypad[i][j]-'0'][k] += dp[keypad[r][c]-'0'][k-1];
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<=9; i++)
            ans += dp[i][n];
        return ans;
	}
	
	bool isValidKey(int i, int j){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j==0) || (i==3 && j==2))
            return false;
        return true;
    }
};