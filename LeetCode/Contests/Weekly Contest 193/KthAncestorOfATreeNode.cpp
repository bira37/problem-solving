class TreeAncestor {
public:
    vector<int> anc[21];
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < 21; i++) anc[i].resize(n + 1);
        for (int i = 0; i < n; i++) {
          anc[0][i] = parent[i];
        }
        for (int i = 1; i < 21; i++) {
          for (int j = 0; j < n; j++) {
            if (anc[i - 1][j] != -1) {
              anc[i][j] = anc[i - 1][anc[i - 1][j]];
            } else {
              anc[i][j] = -1;
            }
          }
        }
    }
    
    int getKthAncestor(int node, int k) {
        cout << node << " " << k << endl;
        for(int i = 20; i >= 0; i--){
            if((1<<i) <= k && anc[i][node] != -1){
                // cout << i << " " << anc[i][node] << endl;
                k -= (1<<i);
                node = anc[i][node];
            }
        }
        if(k != 0) return -1;
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
