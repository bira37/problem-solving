class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> s;
        map<int,int> when;
        vector<int> ans (rains.size(), -1);
        set<int> dry;
        int i = 0;
        for(int x : rains){
            if(x == 0){
                dry.insert(i);
            } else {
                if(s.count(x)){
                    auto it = dry.lower_bound(when[x]);
                    if(it == dry.end()){
                        return vector<int>();
                    } else {
                        ans[*it] = x;
                        dry.erase(it);
                    }
                }
                when[x] = i;
                s.insert(x);
            }
            i++;
        }
        for(int x : dry) ans[x] = 1;
        return ans;
    }
};
