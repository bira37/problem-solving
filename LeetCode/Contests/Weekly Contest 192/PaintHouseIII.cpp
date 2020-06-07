class Solution {
public:
    int inf = 10000000;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        for(int &x : houses) x--;
        int dp[m][n][target+1];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<=target; k++) dp[i][j][k] = -1;
            } 
        }
        for(int j=0; j<n; j++){
            if(houses[0] == -1 || houses[0] == j) dp[0][j][1] = (houses[0] == -1) * cost[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(houses[i] == -1 || houses[i] == j){
                    for(int k=1; k <= target; k++){
                        dp[i][j][k] = inf;
                        for(int j2 = 0; j2 < n; j2++){
                            if(j2 == j && dp[i-1][j2][k] != -1) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j2][k] + (houses[i] == -1)*cost[i][j]);
                            else if(j2 != j && dp[i-1][j2][k-1] != -1) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j2][k-1] + (houses[i] == -1)*cost[i][j]);
                        }
                        if(dp[i][j][k] == inf) dp[i][j][k] = -1;
                    }
                }
            }
        }
        int ans = inf;
        for(int i=0; i<n; i++){
            if(dp[m-1][i][target] != -1) ans = min(ans, dp[m-1][i][target]);
        }
        if(ans == inf) ans = -1;
        return ans;
    }
};
