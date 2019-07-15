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
  
  //int bit 0-1 it finds the index of k-th element active
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

vector<int> sub[112345];

int32_t main(){
  DESYNC;
  int n, m;
  cin >> n >> m;
  BIT bit(n+10);
  for(int i=0; i<n; i++){
    int s,r;
    cin >> s >>r;
    sub[s].pb(r);
  }
  for(int i=0; i<=m; i++) sort(sub[i].begin(), sub[i].end(), greater<int>());
  for(int i=1; i<=m; i++){
    int acc = 0;
    for(int j=0; j<sub[i].size(); j++){
      acc +=  sub[i][j];
      if(acc >= 0) bit.update(j+1, acc);
    }
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    ans = max(ans, bit.query(i, i));
  }
  cout << ans << endl;   
}

