class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int m = ((arr.size() - 1) / 2);
        vector<int> srt(arr);
        sort(srt.begin(), srt.end());
        int mean = srt[m];
        vector<pair<int,int>> strong;
        for(int x : arr){
            strong.push_back(make_pair(abs(mean - x), x));
        }
        sort(strong.begin(), strong.end(), greater<pair<int,int>>());
        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(strong[i].second);
        return ans;
    }
};
