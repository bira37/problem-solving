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

int32_t main(){
  DESYNC;
  vector<int> v;
  v.pb(4);
  v.pb(8);
  v.pb(15);
  v.pb(16);
  v.pb(23);
  v.pb(42);
  int x;
  map<int, ii> m;
  for(int i=0; i<6; i++){
    for(int j=i+1; j<6; j++) m[v[i]*v[j]] = ii(v[i], v[j]);
  }
  vector<int> ans;
  cout << "? 1 2" << endl;
  cout.flush();
  cin >> x;
  ii a = m[x];
  cout << "? 2 3" << endl;
  cout.flush();
  cin >> x;
  ii b = m[x];
  if(a.ff == b.ss){
    swap(a.ff, a.ss);
    swap(b.ff, b.ss);
  }
  else if(a.ff == b.ff) swap(a.ff, a.ss);
  else if(a.ss == b.ss) swap(b.ff, b.ss);
  ans.pb(a.ff);
  ans.pb(a.ss);
  ans.pb(b.ss);
  for(int i=3; i<=4; i++){
    cout << "? " << i << " " << i+1 << endl;
    cout.flush();
    cin >> x;
    ans.pb(x/ans.back());
  }
  for(int x : v){
    if(find(ans.begin(), ans.end(), x) == ans.end()) ans.pb(x);
  }
  cout << "!";
  for(int x : ans) cout << " " << x;
  cout << endl;
  cout.flush(); 
}

