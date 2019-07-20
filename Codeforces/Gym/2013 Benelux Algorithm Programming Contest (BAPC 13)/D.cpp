#include <bits/stdc++.h>
 
using namespace std;
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))
 
// #define DEBUG
#ifdef DEBUG
    #define debug(x) cout << x
#else
    #define debug(x) do {} while(0)
#endif
 
typedef pair<int,int> ii;
typedef vector< int > vi;
typedef vector< ii > vii;
 
int _gcd(int a, int b) { return b == 0 ? a : _gcd(b, a%b); }
int gcd(int a, int b) { return _gcd(abs(a), abs(b)); }
 
int cost[4][2123];
vector< pair<int, int> > adj[2123];
 
int n,m,t;
int s,g,h;
 
int dij(int s, int y) {
  priority_queue< tuple<int,int>, vector< tuple<int,int> >, greater< tuple<int,int> > > pq;
    for(int i = 1; i <= n; i++) {
      cost[y][i] = INT_MAX;
    }
    cost[y][s] = 0;
    pq.push(make_tuple(0, s));
    
    while(!pq.empty()) {
      int v, d;
      tie(d,v) = pq.top();
      pq.pop();
      if(d != cost[y][v]) continue;
      for(ii ad : adj[v]) {
        if((cost[y][v] + ad.S) < cost[y][ad.F]) {
          cost[y][ad.F] = cost[y][v] + ad.S;
          pq.push(make_tuple(cost[y][ad.F], ad.F));
        }
      }
    }
}
 
 
int32_t main() {
    DESYNC;
  
  int T;
  cin >> T;
  while(T--) {
 
    cin >> n >> m >> t;
    
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
 
    cin >> s >> g >> h;
    int a,b, d;
    int are;
    for(int i = 0; i < m; i++) {
      cin >> a >> b >> d;
      if(min(a,b) == min(g,h) && max(a,b) == max(g,h)) {
        are = d;
      }
      adj[a].pb(make_pair(b, d));
      adj[b].pb(make_pair(a, d));
    }
    vector<int> x(t);
    for(int i = 0; i < t; i++) {
      cin >> x[i];
    }
    
    dij(s, 0);
    dij(s, 1);
    dij(h, 2);
    dij(g, 3);
    
    
    vi ans;
    for(int xx : x) {
      //cout << cost[0][xx] << " " << cost[1][g] << " " << are << " " << cost[2][xx] << endl;
      //cout << cost[0][xx] << " " << cost[1][h] << " " << are << " " << cost[3][xx] << endl;
      if(cost[0][xx] == cost[1][g] + are + cost[2][xx]) ans.pb(xx);
      else if(cost[0][xx] == cost[1][h] + are + cost[3][xx]) ans.pb(xx);
    }
    sort(ans.begin(), ans.end());
    for(int an : ans) {
      cout << an << " ";
    }
    cout << endl;
    
    /*vi ans;
    for(int xx : x) {
      if(cost[xx] == cost2[xx]) ans.pb(xx);
    }
    sort(ans.begin(), ans.end());
    for(int an : ans) {
      cout << an << " ";
    }
    cout << endl;*/
  }
}
