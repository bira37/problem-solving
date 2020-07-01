class Solution {
public:
    #define ll long long
    ll M = 1000000007;
    ll exp(ll n, ll k){
        if(k== 0) return 1;
        if(k == 1) return n;
        ll ax = exp(n, k/2);
        ax = (ax*ax)%M;
        if(k%2) ax = (ax*n)%M;
        return ax;
    }
    ll numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ll l = 0, r = nums.size()-1;
        ll ans = 0;
        while(l<=r){
            if(nums[l] + nums[r] > target){
                r--;
            } else {
                ans += exp(2, r-l);
                ans %= M;
                l++;
            }
        }
        return ans;
    }
};
