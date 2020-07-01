class Solution {
public:
    vector<int> g[20+1];
    vector<int> in, out;
    vector<int> dp;
    int setBits(int x){
        int ans = 0;
        while(x){
            ans += (x & 1);
            x /= 2;
        }
        return ans;
    }
    
    int solve(vector<int> q, int n, int k){
        if(q.size() == 0) return 0;
        int qs = q.size();
        int val = 0;
        for(int i=0; i<qs; i++){
            val |= (1<<q[i]);
        }
        if(dp[val] != -1) return dp[val];
        dp[val] = 112345;
        for(int msk = 0; msk < (1<<qs); msk++){
            if(setBits(msk) != min(qs, k)) continue;
            vector<int> nq;
            for(int i=0; i<qs; i++){
                if(msk & (1<<i)){
                    for(int v : g[q[i]]){
                        in[v]--;
                        if(in[v] == 0) nq.push_back(v);
                    }
                } else {
                    nq.push_back(q[i]);
                }
            }
            dp[val] = min(dp[val], solve(nq, n, k));
            for(int i=0; i<qs; i++){
                if(msk & (1<<i)){
                    for(int v : g[q[i]]){
                        in[v]++;
                    }
                }
            }
        }
        dp[val]++;
        return dp[val];
    }
    
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        in.resize(n+1, 0); out.resize(n+1, 0);
        dp.resize(1<<(n+1), -1);
        int ans = 0;
        for(int i=0; i<dependencies.size(); i++){
            int u = dependencies[i][0];
            int v=  dependencies[i][1];
            g[u].push_back(v);
            out[u]++;
            in[v]++;
        }
        vector<int> q;
        for(int i=1; i<=n; i++) if(in[i] == 0) q.push_back(i);
        
        return solve(q, n, k);
    }
};
