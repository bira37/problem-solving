class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> v;
        bool haszero = false;
        int l = 1123456, r = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                haszero = true;
                if(l != 1123456 && r != -1) v.emplace_back(l, r);
                l = 1123456, r = -1;
            } else {
                l = min(l, i);
                r = max(r, i);
            }
        }
        if(l != 1123456 && r != -1) v.emplace_back(l, r);
        int ans = 0;
        for(int i=0; i<(int)(v.size())-1; i++){
            if(v[i+1].first - v[i].second == 2) ans = max(ans, (v[i+1].second - v[i+1].first+1) + (v[i].second - v[i].first+1));
        }
        for(int i=0; i<v.size(); i++){
            //cout << v[i].first << " " <<v[i].second << endl;
            ans = max(ans, (v[i].second - v[i].first+1) - (!haszero));
        }
        return ans;
    }
};
