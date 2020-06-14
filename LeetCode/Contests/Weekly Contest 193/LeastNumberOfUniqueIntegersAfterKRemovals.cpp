class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> cnt;
        for(int x : arr) cnt[x]++;
        vector<int> v;
        for(pair<int,int> p : cnt){
            v.push_back(p.second);
        }
        sort(v.begin(), v.end());
        int tot = v.size();
        for(int i=0; i<v.size(); i++){
            int tira = min(v[i], k);
            k -= tira;
            v[i] -= tira;
            if(v[i] > 0) break;
            tot--;
        }
        return tot;
    }
};
