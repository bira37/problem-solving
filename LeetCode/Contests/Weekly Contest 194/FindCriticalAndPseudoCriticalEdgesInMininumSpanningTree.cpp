class Solution {
public:
    int uf[123];
    void init(){
        for(int i=0; i<123; i++){
            uf[i] = i;
        }
    }
    int find(int u){
        if(u == uf[u]) return u;
        else return uf[u] = find(uf[u]);
    }
    bool merge(int u, int v){
        int x= find(u), y = find(v);
        if(x == y) return false;
        if(rand()%2) swap(x,y);
        uf[y] = x;
        return true;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++){
            reverse(edges[i].begin(), edges[i].end());
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end());
        int mst_val = 0;
        init();
        for(int i=0; i<edges.size(); i++){
            mst_val += merge(edges[i][1], edges[i][2])*edges[i][0];
        }
        vector<int> A;
        set<int> B;
        for(int i=0; i<edges.size(); i++){
            init();
            int cur = 0;
            for(int j=0; j<edges.size(); j++){
                if(j == i) continue;
                cur += merge(edges[j][1], edges[j][2])*edges[j][0];
            }
            //cout << mst_val << " " << cur << " " << edges[i][3] << endl;
            bool ok = true;
            for(int i=0; i<n; i++) if(find(0) != find(i)) ok = false;
            if(mst_val != cur || !ok) A.push_back(edges[i][3]);
            else B.insert(edges[i][3]);
        }
        init();
        for(int i=0; i<edges.size(); i++){
            vector<vector<int>> batch;
            int j = i;
            while(j < edges.size() && edges[i][0] == edges[j][0]) batch.push_back(edges[j++]);
            i = j-1;
            for(auto e : batch){
                if(find(e[1]) == find(e[2]) && B.count(e[3])) B.erase(e[3]);
            }
            for(auto e : batch){
                merge(e[1], e[2]);
            }
        }
        vector<int> C;
        for(int x : B) C.push_back(x);
        vector<vector<int>> ans;
        ans.push_back(A); ans.push_back(C);
        return ans;
    }
};
