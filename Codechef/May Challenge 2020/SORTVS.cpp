#include <bits/stdc++.h>

#define int short
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e3
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

// UF
int uf[20];
int sz[20];

int find(int u){
  if(uf[u] == u) return u;
  else return uf[u] = find(uf[u]);
}

bool merge(int a, int b){
  int x = find(a);
  int y = find(b);
  if(x == y) return false;
  if(sz[x] < sz[y]) swap(x,y);
  uf[y] = x;
  sz[x] += sz[y];
  return true;
}
// UF END

bool sorted(vector<int> & v){
  for(int i=0; i<v.size(); i++) if(v[i] != i) return false;
  return true;
}

int equals(vector<int> & v){
  int ans = 0;
  for(int i=0; i<v.size(); i++) if(v[i] == i) ans++;
  return ans;
}

vector<int> solve(vector<int> v){
  // case 1: mirror
  for(int i=0; i<v.size(); i++){
    if(v[i] == i) continue; //sorted

    if(v[v[i]] == i){
      swap(v[v[i]], v[i]);
      return v;
    }
  }

  // case 2: my pair is at the group of my guy
  for(int i=0; i<v.size(); i++){
    if(v[i] == i) continue; //sorted
    int k = v[i];
    for(int j=0; j<v.size(); j++){
      if(i == j) continue;
      if(v[j] == i && find(k) == find(j)){
        swap(v[j], v[k]);
        swap(v[i], v[k]);
        return v;
      }
    }
  }

  // case 3: find the pair of the leader of this place
  for(int i=0; i<v.size(); i++){
    if(v[i] == i) continue; //sorted

    int k = -1;
    for(int j=0; j<v.size(); j++){
      if(i == j) continue;
      if(v[j] == i){
        k = j;
        break;
      }
    }

    for(int j=0; j<v.size(); j++){
      if(i == j || j == k) continue;
      if(v[j] == k && find(j) == find(i)){
        swap(v[i], v[j]);
        swap(v[i], v[k]);
        return v;
      }
    }
  }

  // case 4 : loukura
  for(int i=0; i<v.size(); i++){
    if(v[i] == i) continue; //sorted
    for(int j=0; j<v.size(); j++){
      if(i == j || v[j] == j) continue;

      // i and j needs to be replaced
      for(int l = 0; l < v.size(); l++){
        if(i == l || j == l || v[l] == l) continue;
        if(v[l] == j && find(l) == find(i)){
          for(int r = 0; r < v.size(); r++){
            if(i == r || j == r || l == r || v[r] == r) continue;
            if(v[r] == i && find(r) == find(j)){
              // OPA
              swap(v[i], v[l]);
              swap(v[j], v[r]);
              swap(v[i], v[j]);
              return v;
            }
          }
        }
      }
    }
  }

  return vector<int>();
}

void solution(int testcase) { 
  int n,m;
  cin >> n >> m;
  vector<int> v(n);

  for(int i=0; i<n; i++){
    uf[i] = i;
    sz[i] = 1;
  }

  // read model
  for(int i=0; i<n; i++){
    cin >> v[i];
    v[i]--;
  }

  // read ops
  for(int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    x--,y--;
    merge(x,y);
  }

  // group all values
  set<int> g[n];
  for(int i=0;i<n; i++) g[find(i)].insert(v[i]);

  vector<bool> vis(n, false);
  // fix all possible zero cost positions
  for(int i=0; i<n; i++){
    int lead = find(i);
    if(g[lead].count(i)){
      vis[i] = true;
      g[lead].erase(i);
      v[i] = i;
    }
  }
  //put the others into any position
  for(int i=0; i<n; i++){
    if(vis[i]) continue;
    int lead = find(i);
    v[i] = *g[lead].begin();
    g[lead].erase(g[lead].begin());
  }


  // SOLVE
  // tuple(dist, equal, depth, vec)
  set< tuple<int, int, int, vector<int>> > q;
  map<vector<int>, tuple<int,int,int>> dst;
  q.insert(mt(0, 0, 0, v));
  dst[v] = mt(0,0,0);
  while(q.size() > 0){
    auto cur = get<3>(*q.begin());
    int d = get<0>(*q.begin());
    int eq = get<2>(*q.begin());
    int depth = get<1>(*q.begin());
    q.erase(q.begin());
    if(dst[cur] < mt(d, eq, depth)) continue;
    if(sorted(cur)){
      cout << d << endl;
      return;
    }
    // solve the best case
    auto nxt = solve(cur);
    if(nxt.size() > 0){
      int eqs = equals(nxt);
      if(!dst.count(nxt)) dst[nxt] = mt(INF, -INF, INF);
      if(dst[nxt] > mt(d+1, depth, -eq)){
        q.insert(mt(d+1, depth, -eq, nxt));
        dst[nxt] = mt(d+1, depth, -eq);
      }
      continue;
    }

    int cnt = 0;
    for(int i=0; i<cur.size(); i++){
      if(cur[i] == i) continue; //sorted;
      vector<int> nw;
      for(int x : cur) nw.pb(x);
      swap(nw[i], nw[nw[i]]);
      int eqs = equals(nw);
      if(!dst.count(nw)) dst[nw] = mt(INF, -INF, INF);
      if(dst[nw] > mt(d+1, depth+1, -eq)){
        q.insert(mt(d+1, depth+1, -eq, nw));
        dst[nw] = mt(d+1, depth+1, -eq);
      }
      cnt++;
      if(cnt >= 5) break;
    }
  }

  // Rerun
  q.clear();
  dst.clear();
  q.insert(mt(0, 0, 0, v));
  dst[v] = mt(0,0,0);
  while(q.size() > 0){
    auto cur = get<3>(*q.begin());
    int d = get<0>(*q.begin());
    int eq = get<2>(*q.begin());
    int depth = get<1>(*q.begin());
    q.erase(q.begin());
    if(dst[cur] < mt(d, eq, depth)) continue;
    if(sorted(cur)){
      cout << d << endl;
      return;
    }
    // solve the best case
    auto nxt = solve(cur);
    if(nxt.size() > 0){
      int eqs = equals(nxt);
      if(!dst.count(nxt)) dst[nxt] = mt(INF, -INF, INF);
      if(dst[nxt] > mt(d+1, 0, -eq)){
        q.insert(mt(d+1, 0, -eq, nxt));
        dst[nxt] = mt(d+1, 0, -eq);
      }
      continue;
    }

    //case mismatch
    for(int i=0; i<cur.size(); i++){
      if(cur[i] == i) continue; //sorted;
      vector<int> nw;
      for(int x : cur) nw.pb(x);
      swap(nw[i], nw[nw[i]]);
      int eqs = equals(nw);
      if(!dst.count(nw)) dst[nw] = mt(INF, -INF, INF);
      if(dst[nw] > mt(d+1, depth+1, -eq)){
        q.insert(mt(d+1, depth+1, -eq, nw));
        dst[nw] = mt(d+1, depth+1, -eq);
      }
    }
  }
}

int32_t main() {
  DESYNC;
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++)
    solution(_testcase);
}

