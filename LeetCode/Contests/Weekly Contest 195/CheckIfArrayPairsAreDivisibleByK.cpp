class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        multiset<int> s;
        for(int x : arr){
            int y = (x%k + k)%k;
            if(s.find((k-y)%k) != s.end()) s.erase(s.find((k-y)%k));
            else s.insert(y);
        }
        return s.size() == 0;
    }
};
