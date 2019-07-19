#include <bits/stdc++.h>
 
#define int long long
#define double long double
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
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct BIT {
  
  vector<int> bit;
 
  BIT() {}
  
  int n;
   
  BIT(int n) {
    this->n = n;
    bit.resize(n+1);
  }
 
  void update(int idx, int val){
	  for(int i = idx; i <= n; i += i&-i){
		  bit[i]+=val;
	  }
  }
 
  int prefix_query(int idx){
	  int ans = 0;
	  for(int i=idx; i>0; i -= i&-i){
		  ans += bit[i];
	  }
	  return ans;
  }
  
  int query(int l, int r){
	  return prefix_query(r) - prefix_query(l-1);
  }
  
  int kth(int k) {
    int cur = 0;
    int acc = 0;
    for(int i = 19; i >= 0; i--) {
      if(cur + (1<<i) > n) continue;
      if(acc + bit[cur + (1<<i)] < k) {
        cur += (1<<i);
        acc += bit[cur];
      }
    }
    return ++cur;
  }
  
};
 
int32_t main(){
  //DESYNC;
  int n;
  cin >> n;
  int v[n];
  int d[n];
  
  BIT bit1(n), bit2(n);
  
  map<int, vector< ii >, greater<int> > m;
  for(int i=0; i<n; i++) cin >> v[i];
  for(int i=0; i<n; i++) cin >> d[i];
  vector < ii > a;
  for(int i=0; i<n; i++){
    a.pb(ii(d[i], v[i]));
  }  
  sort(a.begin(), a.end());
  for(int i=0; i<n; i++){
    m[a[i].ss].pb(ii(i+1, a[i].ff));
    bit1.update(i+1, a[i].ff);
    bit2.update(i+1, 1);
  }
  
  int qtd = 0;
  int acc = 0;
  int ans = INF;
  for(auto x : m){
    int tira = n - (x.ss.size()-1) - x.ss.size();
    //cout << "key " << x.ff << " " << tira << endl;
    tira -= qtd;
    tira = max(0LL, tira);
    for(ii k : x.ss){
      bit2.update(k.ff, -1);
      bit1.update(k.ff, -k.ss);
    } 
    int cur = acc;
    if(tira > 0){
      //cout << bit2.kth(tira) << endl;
      cur += bit1.prefix_query(bit2.kth(tira));
    }
    //cout << cur << endl;
    ans = min(ans, cur);
    qtd += x.ss.size();
    for(ii k : x.ss) acc += k.ss;
  }
  cout << ans << endl;      
}
 
