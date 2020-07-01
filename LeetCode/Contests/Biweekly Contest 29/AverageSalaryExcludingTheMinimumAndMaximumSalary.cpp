class Solution {
public:
    double average(vector<int>& salary) {
        int mn = 11234567;
        int mx = 0;
        int s = 0;
        for(int x : salary){
            mn = min(mn, x);
            mx = max(mx, x);
            s += x;
        }
        return (double)(s - mn - mx)/(double)(salary.size()-2);
    }
};
