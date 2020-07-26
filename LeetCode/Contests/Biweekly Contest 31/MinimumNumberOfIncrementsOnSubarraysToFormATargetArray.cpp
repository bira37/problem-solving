class Solution {
public:
    
    int minNumberOperations(vector<int>& target) {
        
        long long bef = 0;
        long long ans = 0;
        for(int x : target){
            ans += max(0LL, (long long)(x-bef));
            bef = x;
        }
        return ans;
    }
};
