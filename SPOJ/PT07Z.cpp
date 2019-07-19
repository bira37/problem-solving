#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int most_far;
int dist;

vector<int> adj[112345];

void  dfs(int u, int p, int d){
  if(d > dist){
    most_far = u;
    dist = d;
  }
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u, d+1);
  }
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  most_far = dist = -1;
  dfs(1, -1, 0);
  int root = most_far;
  most_far = dist = -1;
  dfs(root, -1, 0);
  
  cout << dist << endl;
}
