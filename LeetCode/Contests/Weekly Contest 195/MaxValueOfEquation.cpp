class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        set<pair<int,int>> s;
        multiset<int, greater<int>> v;
        int ans = -112345677890;
        for(int i=0; i<points.size();  i++){
            int x = points[i][0];
            int y = points[i][1];
            while(s.size() > 0  && s.begin()->first < x - k){
                int pt = s.begin()->second;
                s.erase(s.begin());
                v.erase(v.find(points[pt][1] - points[pt][0]));
            }
            if(s.size() > 0){
                ans = max(ans, y + x + *v.begin());
            }
            v.insert(y - x);
            s.insert(make_pair(x, i));
        }
        return ans;
    }
};
