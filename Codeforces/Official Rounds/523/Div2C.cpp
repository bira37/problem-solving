#include <bits/stdc++.h>

typedef long long ll;

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

vector<int> divs[1123456];

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
      bit[i] = mod(bit[i] + val, M);
    }
  }

  int prefix_query(int idx){
    int ans = 0;
    for(int i=idx; i>0; i -= i&-i){
      ans = mod(ans + bit[i], M);
    }
    return ans;
  }
  
  int query(int l, int r){
    return mod(prefix_query(r) - prefix_query(l-1), M);
  }
  
};

int32_t main(){
  DESYNC;
  BIT bit(1000000);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=i; j<=1000000; j+=i) divs[j].pb(i);
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    for(int j = divs[x].size()-1; j >= 0; j--){
      int d = divs[x][j];
      if(d > i) continue;
      int val = (d-1 == 0 ? 1 : bit.query(d-1, d-1));
      bit.update(d, val);
    }
  }
  cout << bit.query(1, n) << endl;
}

