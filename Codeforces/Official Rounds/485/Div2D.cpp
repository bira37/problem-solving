#include <bits/stdc++.h>

#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1

using namespace std;

inline int mod(int n){ return (n%1000000007); }

vector<int> adj[112345];
int best[112345][101];
int color[112345];

int32_t main(){
	int n,m,k,s;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i=0; i<n; i++){
	  scanf("%d", color+i+1);
	}
	for(int i=0; i<m; i++){
	  int u,v;
	  scanf("%d%d", &u, &v);
	  adj[u].pb(v);
	  adj[v].pb(u);
	}
	
	for(int i=1; i<=n; i++){
	  for(int j=0; j<=100; j++) best[i][j] = 1000000;
	}
	
	for(int i=1; i<=k; i++){
	  //start bfs here
	  queue< ii > q;
	  for(int v = 1; v <= n; v++){
	    if(color[v] != i) continue;
	    q.push({v, 0});
	    best[v][i] = 0;
	  }
	  while(!q.empty()){
	    ii cur = q.front();
	    q.pop();
	    if(best[cur.ff][i] < cur.ss) continue;
	    for(int v : adj[cur.ff]){
	      if(best[v][i] > cur.ss+1){
	        best[v][i] = cur.ss+1;
	        q.push({v, cur.ss+1});
	      }
	    }
	  }
	}
	
	for(int i=1; i<=n; i++){
	  multiset<int> ss;
	  sort(best[i], best[i]+101);
	  int acc = 0;
	  int cnt = 0;
	  for(int j=0; j<s; j++) acc += best[i][j];
	  printf("%d ", acc);
	}
	puts("");
	  
}

