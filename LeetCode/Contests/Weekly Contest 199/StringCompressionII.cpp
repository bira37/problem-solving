class Solution {
public:
    int dp[112][112][16][27];
    int len;
    string str;
    int mx;
    int solve(int n, int k, int cnt, int lst){
        if(k < 0) return 1000000;
        if(n == len) return 0;
        if(dp[n][k][cnt][lst] != -1) return dp[n][k][cnt][lst]; 
        int ans = dp[n][k][cnt][lst];
        ans = 100000;
        
        int ch = str[n]-'a';
        ans = min(ans, solve(n+1, k-1, cnt, lst));
        if(lst == ch){
            ans = min(ans, solve(n+1,k, min(cnt+1, 15), lst) + (min(cnt+1, 15) == 1 || min(cnt+1, 15) == 2 || min(cnt+1, 15) == 10));
        } else {
            ans = min(ans, solve(n+1, k, 1, ch) + 1);
        }
        
        return dp[n][k][cnt][lst] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        //check if all equal
        int cnt = 0;
        char ch = s[0];
        for(char c : s) if(ch == c) cnt++;
        if(cnt == s.size()){
            cnt -=k;
            if(cnt == 0) return 0;
            else if(cnt == 1) return 1;
            else if(cnt >= 2 && cnt <= 9) return 2;
            else if(cnt >= 10 && cnt <= 99) return 3;
            else return 4;
        }
        
        // solve
        this->len = s.size();
        this->str = s;
        this->mx = k;
        memset(dp, -1, sizeof dp);
        return solve(0, k, 0, 26);
    }
};
