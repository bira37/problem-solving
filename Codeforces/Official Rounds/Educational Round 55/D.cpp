#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

vector< int > adj[112345];
int bst = -1;
int root = -1;
int diameter = 0;

void dfs1(int u, int p, int dep){
  if(bst < dep){
    bst = dep;
    root = u;
  }
  for(int v : adj[u]){
    if(v == p) continue;
    dfs1(v, u, dep+1);
  }
}

void dfs2(int u, int p, int dep){
  diameter = max(dep, diameter);
  for(int v : adj[u]){
    if(v == p) continue;
    dfs2(v, u, dep+1);
  }
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector<int> one, more;
  int a[n+1];
  int dg[n+1];
  vector< ii > g;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    dg[i] = 0;
    if(a[i] > 1) more.pb(i);
    else one.pb(i);
  }
  if(n == 1){
    cout << "YES 0" << endl;
    cout << 0 << endl;
    return 0;
  }
  if(n == 2){
    cout << "YES 1" << endl;
    cout << 1 << endl;
    cout << "1 2" << endl;
    return 0;
  }
  int lst = -1;
  for(int x : more){
    if(lst != -1){
      g.pb(ii(lst, x));
      dg[lst]++;
      dg[x]++;
    }
    lst = x;
  }
  queue<int> q;
  if(more.size() > 0) q.push(more.back());
  for(int i = 0; i < (int)more.size()-1; i++){
    int x = more[i];
    if(dg[x] < a[x]) q.push(x);
  }
  for(int x : one){
    if(q.size() == 0){
      cout << "NO" << endl;
      return 0;
    }
    int k = q.front();
    q.pop();
    g.pb(ii(k, x));
    dg[x]++;
    dg[k]++;
    if(dg[k] < a[k]) q.push(k);
  }
  for(ii p : g){
    adj[p.ff].pb(p.ss);
    adj[p.ss].pb(p.ff);
  }
  dfs1(1, -1, 0);
  dfs2(root, -1, 0);
  cout << "YES " << diameter << endl;
  cout << g.size() << endl;
  for(ii p : g) cout << p.ff << " " << p.ss << endl;
}

