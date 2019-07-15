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
#define M 998244353
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

struct Compresser {
  
  vector<int> value;
  
  Compresser() {}
  
  Compresser(int n){
    value.resize(n);
  }
  
  void compress(vector<int> & v){
    vector<int> tmp;
    set<int> s;
    for(int i=0; i<v.size(); i++) s.insert(v[i]);
    for(int x : s) tmp.pb(x);
    for(int i=0; i<v.size(); i++){
      int idx = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
      value[idx] = v[i];
      v[i] = idx;
    }
  }
  
};

int l[212345] = {0};
int r[212345] = {0};

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  Compresser compresser(n);
  compresser.compress(v);
  for(int i=0; i<212345; i++){
    l[i] = INF;
    r[i] = -1;
  }
  for(int i=0; i<n; i++){
    l[v[i]] = min(l[v[i]], i);
    r[v[i]] = max(r[v[i]], i);
  }
  vector< ii > p;
  for(int i=0; i<212345; i++){
    if(l[i] == INF) continue;
    p.pb(ii(l[i], r[i]));
  }
  sort(p.begin(), p.end());
  int cnt = 0;
  int lst = -1;
  for(ii x : p){
    if(x.ff <= lst){
      lst = max(lst, x.ss);
    }
    else {
      cnt++;
      lst = x.ss;
    }
  }
  int ans = 1;
  for(int i=0; i<cnt-1; i++) ans = mod(ans*2LL, M);
  cout << ans << endl;  
}

