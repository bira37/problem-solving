class Solution {
public:
    bool isPathCrossing(string path) {
        int u = 0, v = 0;
        set<pair<int,int>> s;
        s.insert(make_pair(u,v));
        for(char c : path){
            if(c == 'N') u++;
            else if(c == 'S') u--;
            else if(c == 'E') v++;
            else v--;
            if(s.count(make_pair(u,v))) return true;
            s.insert(make_pair(u,v));
        }
        return false;
    }
};
