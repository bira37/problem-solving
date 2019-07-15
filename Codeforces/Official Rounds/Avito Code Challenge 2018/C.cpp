#include <bits/stdc++.h>
#define int long long
using namespace std;

int deg[112345] = {0};
vector<int> adj[112345];
bool vis[112345] = {0};
int p[112345];

void dfs(int u, int pai){
  for(int v : adj[u]){
    if(v == pai) continue;
    p[v] = u;
    dfs(v, u);
  }
}

int32_t main(){
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  set<int> d1;
  int max_d = 0;
  int root = 0;
  for(int i=1; i<=n; i++){
    if(deg[i] == 1) d1.insert(i);
    if(max_d < deg[i]){
      max_d = deg[i];
      root = i;
    }
  }
  dfs(root, 0);
  if(d1.count(root)) d1.erase(root);
  for(int v : d1){
    int cur = v;
    while(cur != root){
      if(vis[cur]){
        cout << "No" << endl;
        return 0;
      }
      vis[cur] = true;
      cur = p[cur];
    }
  }
  cout << "Yes" << endl;
  cout << d1.size() << endl;
  for(int v : d1){
    cout << root << " " << v << endl;
  }
}
  