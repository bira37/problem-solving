#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
vector<int> g[212345];
 
int32_t main(){
  DESYNC;
  int n, m;
  cin >> n >> m;
  vector< ii > v;
  map<int, int> M, Q;
  int A[n];
  for(int i = 0; i<n; i++){
    int x;
    cin >> x;
    A[i] = x;
    v.pb(ii(x, i));
    M[x]++;
  }
  while(m--){
    int a,b;
    cin >> a >> b;
    g[a-1].pb(b-1);
    g[b-1].pb(a-1);
  }
  int ans[n];
  sort(v.begin(), v.end(), greater< ii >());
  int cur = 0;
  for(ii p : v){
    int x, id;
    x = p.ff;
    id = p.ss;
    ans[id] = n-1-cur;
    Q[x]++;
    ans[id] -= (M[x] - Q[x]);
    //cout << x << " " << id << " " << n-1-cur << " " << (M[x] - Q[x]) << endl;
    for(int y : g[id]){
      //cout << A[id] << " " << A[y] << endl;
      if(A[id] > A[y]) ans[id]--;
    }
    cur++;   
  }
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << endl;
}
 
