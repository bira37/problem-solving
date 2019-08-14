#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[1123];
int color[1123];

bool dfs(int u, int c){
  color[u] = c;
  bool ok = true;
  for(int v : adj[u]){
    if(color[v] == color[u]) return false;
    if(color[v] != -1) continue;
    ok = ok & dfs(v, (c == 1 ? 0 : 1));
  }
  return ok;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int teta = 1;
  int n, m;
  while(cin >> n >> m){
    cout << "Instancia " << teta++ << endl;
    for(int i=0; i<=n; i++){
      adj[i].clear();
      color[i] = -1;
    }
    for(int i=0; i<m; i++){
      int u,v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    bool flag = true;
    for(int i=1; i<=n; i++){
      if(color[i] != -1) continue;
      flag = flag & dfs(i, 0);
    }
    if(flag) cout << "sim" << endl;
    else cout << "nao" << endl;
    cout << endl;
  }
}
  
  
