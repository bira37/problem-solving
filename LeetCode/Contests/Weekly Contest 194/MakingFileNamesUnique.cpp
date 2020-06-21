class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        map<string,int> m;
        for(string s : names){
            if(m[s] == 0){
                ans.push_back(s);
                m[s]++;
                continue;
            }
            int k = m[s];
            while(true){
                string t = s + "(" + to_string(k) + ")";
                if(m[t] == 0){
                    ans.push_back(t);
                    m[t]++;
                    m[s]++;
                    break;
                }
                k++;
            }
        }
        return ans;
    }
};
