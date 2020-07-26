class Solution {
public:
    vector<int> squares;
    int dp[112345];
    
    int solve(int n){
        if(n == 0) return 0;
        if(dp[n] !=-1) return dp[n];
        dp[n]  = 0;
        for(int i=0; i<squares.size() && squares[i] <= n; i++){
            int cur = solve(n-squares[i]);
            if(cur == 0) dp[n] =1;
        }
        return dp[n];
    }
    bool winnerSquareGame(int n) {
        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
        }
        memset(dp, -1, sizeof dp);
        int ans = solve(n);
        if(ans == 0) return false;
        else return true;
    }
};
