class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int v[2];
        v[0] = v[1] = 0;
        int ans = 0;
        int s = 0;
        v[0] = 1;
        for(int x : arr){
            s += x;
            if(s%2) ans += v[0];
            else ans += v[1];
            v[s%2]++;
            ans %= 1000000007;
        }
        return ans;
    }
};
