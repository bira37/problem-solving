#include <bits/stdc++.h>

using namespace std;

vector<int> adj[112345];
vector<int> adj_t[112345];
vector<int> scc_adj[112345];
int ed[112345];
int tempo,comp;
bool vis[112345];
int scc[112345];
int n,m;

void dfs(int u){
	vis[u] = true;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
	ed[u] = ++tempo;
}

void dfst(int u, int comp){
	scc[u] = comp;
	vis[u] = true;
	for(int i=0; i<adj_t[u].size(); i++){
		int v = adj_t[u][i];
		if(!vis[v]) dfst(v,comp);
	}
}

bool cmp_end(const int & a, const int & b){
  return ed[a] > ed[b];
}

void calculate_scc(){
  for(int i=0; i<n; i++){
    vis[i] = false;
  }
  for(int i=0; i<n; i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  vector<int> vertex(n+1);
  for(int i=0; i<n; i++){
    vis[i] = false;
    vertex[i] = i;
  }
  sort(vertex.begin(), vertex.end(), cmp_end);
  comp=-1;
  for(int i=0; i<vertex.size(); i++){
    if(!vis[vertex[i]]){
      comp++;
      dfst(vertex[i],comp);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<adj[i].size(); j++){
      int v = adj[i][j];
      if(scc[i] != scc[v]){
        scc_adj[scc[i]].push_back(scc[v]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  tempo = 0;
  for(int i=0; i<n; i++){
    adj[i].clear();
    adj_t[i].clear();
    scc_adj[i].clear();
    ed[i] = -1;
    vis[i] = false;
  }
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    u--, v--;
    adj[v].push_back(u);
    adj_t[u].push_back(v);
  }
  calculate_scc();
  int dg_in[comp+1];
  for(int i=0; i<=comp; i++) dg_in[i] = 0;
  for(int i=0; i<=comp; i++){
    for(int j=0; j<scc_adj[i].size(); j++){
      int v = scc_adj[i][j];
      dg_in[v]++;
    }
  }
  int cont = 0;
  int ans = -1;
  for(int i=0; i<=comp; i++){
    if(dg_in[i] == 0){
      cont++;
      ans = i;
    }
  }
  if(cont != 1) cout << 0 << endl;
  else {
    set<int> s;
    for(int i=0; i<n; i++){
      if(scc[i] == ans) s.insert(i+1);
    }
    bool flag = true;
    cout << s.size() << endl;
    for(int x : s){
      if(flag){
        cout << x;
        flag= false;
      }
      else cout << " " << x;
    }
    cout << endl;
  }
}
