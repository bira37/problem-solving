class Solution {
public:
    int minFlips(string target) {
        string cur;
        for(char c : target) cur += '0';
        int ans = 0;
        int flips = 0;
        for(int i=0; i<cur.size(); i++){
            if(flips%2) cur[i] = '1';
            else cur[i] = '0';
            if(cur[i] != target[i]){
                flips++;
                ans++;
                if(flips%2) cur[i] = '1';
                else cur[i] = '0';
            }
        }
        return ans;
    }
};
