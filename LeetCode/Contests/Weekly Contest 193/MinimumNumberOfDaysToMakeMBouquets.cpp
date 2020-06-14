class Solution {
public:
    vector<int> check(vector<int>& bloom, int m, int k){
        vector<int> ans;
        vector<int> v;
        v.push_back(0);
        for(int x : bloom) v.push_back(x);
        deque<pair<int,int>> dq;
        for(int i=0; i<k; i++) {
            while(dq.size() > 0 && dq.back().first <= v[i]) dq.pop_back();
            dq.push_back(make_pair(v[i], i));
        }
        for(int i=k; i<v.size(); i++){
            while(dq.size() > 0 && dq.front().second <= i-k) dq.pop_front();
            while(dq.size() > 0 && dq.back().first <= v[i]) dq.pop_back();
            dq.push_back(make_pair(v[i], i));
            ans.push_back(dq.front().first);
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> v = check(bloomDay, m, k);
        int l = 0, r = 1e9+10;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            int cnt = m;
            for(int i=0; i<v.size(); i++){
                if(v[i] <= mid){
                    cnt--;
                    i += k-1;
                }
            }
            if(cnt <= 0){
                ans = mid;
                r = mid -1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};
