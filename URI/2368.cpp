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

vector<ii> v;

ii cut(int x){
  int acc = 0;
  if(acc == x) return ii(-1, false);
  int idx;
  for(int i=0; i<v.size(); i++){
    acc += abs(v[i].ss - v[i].ff)+1;
    if(acc >= x){
      idx = i;
      break;
    }
  }
  if(acc == x) return ii(idx, false);
  
  if(v[idx].ff < v[idx].ss){
    int len = acc - x;
    v[idx].ss -= len;
    v.insert(v.begin()+idx+1, ii(v[idx].ss+1, v[idx].ss+len));
  }
  else {
    int len = acc - x;
    v[idx].ss += len;
    v.insert(v.begin()+idx+1, ii(v[idx].ss-1, v[idx].ss-len));
  }
  return ii(idx, true);
}

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  v.pb(ii(1, n));
  while(m--){
    char c;
    int l,r;
    cin >> c >> l >> r;
    if(c == 'I'){
      ii id_l = cut(l-1);
      ii id_r = cut(r);
      int iter_l = id_l.ff+1;
      int iter_r = id_r.ff;
      for(int i=iter_l; i<=iter_r; i++) swap(v[i].ff, v[i].ss);
      reverse(v.begin()+iter_l, v.begin()+iter_r+1);
      //cout << "query " << iter_l << " " << iter_r << endl;
      //for(ii x : v) cout << x.ff << " " << x.ss << endl;
    }
    else {
      ii id_l = cut(l-1);
      ii id_r = cut(r);
      int iter_l = id_l.ff+1;
      int iter_r = id_r.ff;
      int ans = 0;
      for(int i=iter_l; i<=iter_r; i++){
        int a = v[i].ff, b = v[i].ss;
        if(a > b) swap(a,b);
        ans += ((a+b)*(b-a+1))/2;
      }
      //cout << "ans" <<endl;
      cout << ans << endl;
    }
  }
}


