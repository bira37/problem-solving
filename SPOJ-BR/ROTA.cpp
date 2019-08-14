#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
bool vis[101];

map<string, int> str_to_int;
map< pair<string, string>, int > get_order;
map<int, string> int_to_str;
vector< pair<int, int> > e;

void predfs(int u){
  vis[u] = true;
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    if(vis[v]) continue;
    e.push_back(make_pair(u,v));
    predfs(v);
  }
}

void dfs(int u, pair<int, int> cut){
  vis[u] = true;
  bool flag = true;
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    if((u == cut.first && v == cut.second) && flag){
      flag = false;
      continue;
    }
    if(vis[v]) continue;
    dfs(v, cut);
  }
}

bool cmp(const pair<string, string> & a, const pair<string, string> & b){
	return get_order[a] < get_order[b];
}

int main(){
	int n,m;
	while(cin >> n >> m, n | m){
		str_to_int.clear();
		int_to_str.clear();
		e.clear();
		for(int i=0; i<n; i++){
			adj[i].clear();
			vis[i] = false;
		}

		for(int i=0; i<n; i++){
			string x;
			cin >> x;
			str_to_int[x] = i;
			int_to_str[i] = x;
		}
		
		for(int i=0; i<m; i++){
			string u,v;
			cin >> u >> v;
			adj[str_to_int[v]].push_back(str_to_int[u]);
			get_order[pair<string, string>(u,v)] = i;
		}

    predfs(0);
    vector< pair<string, string> > bridges;
    for(int i = 0; i<e.size(); i++){
      for(int j = 0; j<n ; j++) vis[j] = false;
      dfs(0,e[i]);
      int count = 0;
      for(int j=0; j<n; j++) if(!vis[j]) count++;
      if(count > 0) bridges.push_back(pair<string, string>(int_to_str[e[i].second],int_to_str[e[i].first]));
    }
		
		sort(bridges.begin(), bridges.end(), cmp);
		for(int i=0; i<bridges.size(); i++) cout << bridges[i].first << " " << bridges[i].second << endl;
		
		if(bridges.size() == 0) cout << "Nenhuma" << endl;
		cout << endl;
	}
}
		
		
	

