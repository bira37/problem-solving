class Solution {
public:
    typedef long long ll;
    const int M = 1000000007;
    
    ll solve(vector<int>& v, vector<int>& w){
        vector<ll> pv, pw;
        for(int x : v){
            if(pv.size() == 0) pv.push_back(x);
            else pv.push_back(pv.back()+x);
        }
        for(int x : w){
            if(pw.size() == 0) pw.push_back(x);
            else pw.push_back(pw.back()+x);
        }
        ll ans = 0;
        ll last_match = -1;
        for(int i=0; i<v.size(); i++){
            // putting v[i]
            // check whether it exists on w
            ll it = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
            if(it >= w.size() || w[it] != v[i]){
                // no match, just put v[i] on ans
                ans += v[i];
            } else {
                //matched 
                if(last_match == -1){
                    last_match = it;
                    ans += v[i];
                }
                else {
                    ll it2 = lower_bound(v.begin(), v.end(), w[last_match]) - v.begin();
                    ll pfirst = pv[i] - (it2 > -1 ? pv[it2] : 0);
                    ll psecond = pw[it] - (last_match > -1 ? pw[last_match] : 0);
                    //cout << pfirst << " " << psecond << endl;
                    if(psecond > pfirst) ans += max(pfirst, psecond) - min(pfirst, psecond);
                    ans += v[i];
                    last_match = it;
                }
            }
            //cout << "after " << v[i] << " ans is " << ans << endl;
        }
        //cout << "current is " << ans << endl;
        //adjust ending
        if(last_match != -1){
            ll it2 = lower_bound(v.begin(), v.end(), w[last_match]) - v.begin();
            ll pfirst = pv.back() - (it2 > -1 ? pv[it2] : 0);
            ll psecond = pw.back() - (last_match > -1 ? pw[last_match] : 0);
            //cout << pfirst << "  " << psecond << endl;
            if(psecond > pfirst) ans += max(pfirst, psecond) - min(pfirst, psecond);
        }
        return ans;
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1))%M;
    }
};
