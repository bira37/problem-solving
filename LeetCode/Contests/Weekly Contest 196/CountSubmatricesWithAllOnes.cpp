class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i<=n; i++){
            int acc = 0;
            for(int j=1; j<=m; j++){
                acc += mat[i-1][j-1];
                dp[i][j] = acc + dp[i-1][j];
            }
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                for(int k=i; k<=n; k++){
                    for(int l=j; l<=m; l++){
                        //cout << "try " << i << " " << j << " " << k << " " << l << endl;
                        int val = dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1];
                        //cout << val << endl;
                        if(val == (k-i+1)*(l-j+1)){
                            //cout << i << " " << j << " " << k << " " << l << endl;
                            ans++;
                        } else break;
                    }
                }
            }
        }
        return ans;
    }
};
