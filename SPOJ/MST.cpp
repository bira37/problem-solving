#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[11234];
vector<int> adjc[11234];
int d[11234];

int32_t main(){
  int n,m;
  scanf("%lld%lld", &n, &m);
  
  for(int i=0; i<=n; i++){
    d[i] = (int)1e9;
  }
  
  for(int i=0; i<m; i++){
    int a,b,c;
    scanf("%lld%lld%lld", &a, &b, &c);
    adj[a].push_back(b);
    adj[b].push_back(a);
    adjc[a].push_back(c);
    adjc[b].push_back(c);
  }
  
  set< pair<int,int> > s;
  
  d[1] = 0;
  for(int i=1; i<=n; i++){
    s.insert(make_pair(d[i], i));
  }
  
  int mst_w = 0;
  
  while(!s.empty()){
    int u = s.begin()->second;
    mst_w += s.begin()->first;
    
    s.erase(s.begin());
    
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i];
      int c = adjc[u][i];
      
      if(d[v] <= c) continue;
      if(s.find(make_pair(d[v], v)) != s.end()){
        s.erase(s.find(make_pair(d[v], v)));
        d[v] = c;
        s.insert(make_pair(d[v], v));
      }
    }
  }
  
  printf("%lld\n", mst_w);
}
    
