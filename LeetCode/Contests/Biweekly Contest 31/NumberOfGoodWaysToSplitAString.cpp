class Solution {
public:
    int numSplits(string s) {
        vector<int> cnta(26, 0), cntb(26, 0);
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            cnta[s[i]-'a']++;
        }
        int da = 0, db= 0;
        for(int i=0; i<26; i++){
            if(cnta[i] > 0) da++;
            if(cntb[i] > 0) db++;
        }
        ans += (da==db);
        for(int i=0; i<s.size(); i++){
            cnta[s[i]-'a']--;
            cntb[s[i]-'a']++;
            int da = 0, db= 0;
        for(int i=0; i<26; i++){
            if(cnta[i] > 0) da++;
            if(cntb[i] > 0) db++;
        }
        ans += (da==db);
        }
        return ans;
    }
};
