#include <bits/stdc++.h>

using namespace std;

set<int> adj[212345];
set<int> to_vis;
vector<int> ans;

void visit(int x){
  queue<int> q;
  q.push(x);
  to_vis.erase(to_vis.find(x));
  while(!q.empty()){
    int u = q.front();
    q.pop();
    ans.back()++;
    vector<int> to_rem;
    for(int v : to_vis){
      if(adj[u].count(v)) continue;
      q.push(v);
      to_rem.push_back(v);
    }
    for(int v : to_rem) to_vis.erase(to_vis.find(v));
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) to_vis.insert(i);
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  int cmp = 0;
  for(int i=1; i<=n; i++){
    if(to_vis.count(i)){
      ans.push_back(0);
      visit(i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(int i=0; i<ans.size(); i++){
    if(i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}