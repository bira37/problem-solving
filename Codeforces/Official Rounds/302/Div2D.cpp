#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[3123];
int dist[3123][3123];
 
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      dist[i][j] = int(1e9);
    }
  }
  
  for(int i=0; i<m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int s1,e1,l1,s2,e2,l2;
  cin >> s1 >> e1 >> l1 >> s2 >> e2 >> l2;
  
  for(int i=1; i<=n; i++){
    queue< pair<int,int> > q;
    q.push({i, 0});
    while(!q.empty()){
      auto cur = q.front();
      q.pop();
      if(cur.second > dist[i][cur.first]) continue;
      dist[i][cur.first] = cur.second;
      for(int v : adj[cur.first]){
        if(dist[i][v] > cur.second + 1){
          dist[i][v] = cur.second+1;
          q.push({v, cur.second+1});
        }
      }
    }
  }
  int ans = int(1e9);
  int n1 = dist[s1][e1];
  int n2 = dist[s2][e2];
  if(n1 <= l1 && n2 <= l2) ans = min(ans, n1+n2);
  for(int u = 1; u <= n; u++){
    for(int v = 1; v <= n; v++){
       bool ok1 = false;
       bool ok2 = false;
       int n1 = min(dist[s1][u] + dist[u][v] + dist[v][e1], dist[s1][v] + dist[u][v] + dist[u][e1]);
       int n2 = min(dist[s2][u] + dist[u][v] + dist[v][e2], dist[s2][v] + dist[u][v] + dist[u][e2]);
       if(n1 <= l1) ok1 = true;
       if(n2 <= l2) ok2 = true;
       if(!ok1 || !ok2) continue;
       ans= min(ans, n1 + n2 - dist[u][v]);
    }
  }
  
  if(ans == int(1e9)) cout << -1 << endl;
  else cout << m - ans << endl;
}
       
