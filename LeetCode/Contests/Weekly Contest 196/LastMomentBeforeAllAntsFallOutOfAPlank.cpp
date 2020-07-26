class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx = 0;
        for(int x : left){
            int dst = x;
            mx = max(mx, dst);
        }
        for(int x : right){
            int dst = n-x;
            mx = max(mx, dst);
        }
        return mx;
    }
};
