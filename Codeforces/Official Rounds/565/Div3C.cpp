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
  int n;
  cin >> n;
  vector<int> v;
  v.pb(4); v.pb(8); v.pb(15); v.pb(16); v.pb(23); v.pb(42);
  map<int, vector<int> > m;
  int ans = 0;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    if(find(v.begin(), v.end(), x) == v.end()){}
    else m[x].pb(i);
  }
  for(int x : v) reverse(m[x].begin(), m[x].end());
  while(true){
    int lst = -1;
    bool ok = true;
    for(int x : v){
      while(m[x].size() > 0 && lst > m[x].back()){
        m[x].pop_back();
      }
      if(m[x].size() == 0){
        ok = false;
        break;
      }
      else lst = m[x].back();
    }
    if(!ok) break;
    for(int x : v) m[x].pop_back();
    ans += v.size();
  }
  cout << n - ans << endl;
}

