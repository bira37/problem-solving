#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

typedef tree<
ii, //change for pair<int,int> to use like multiset
null_type,
less<ii>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

void brute(int l, int r, int *a, int *b, vector<ii> & m, ii cur, int h){
  if(l == r){
    m.pb(cur);
    return;
  }
  
  //only a
  brute(l+1, r, a, b, m, ii(cur.ff+a[l], cur.ss), h);

  //only b
  brute(l+1, r, a, b, m, ii(cur.ff, cur.ss+b[l]), h);

  //both
  brute(l+1, r, a, b, m, ii(cur.ff+a[l], cur.ss+b[l]), h);
}

int solve(){
  int n;
  int h;
  cin >> n >> h;
  int a[n], b[n];
  int ans = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<n; i++){
    cin >> b[i];
  }
  vector<ii> m1, m2;
  brute(0, n/2, a, b, m1, ii(0,0), h);
  brute(n/2, n, a, b, m2, ii(0,0), h);

  sort(m1.begin(), m1.end());
  sort(m2.begin(), m2.end());

  int key = 0;
  ordered_set s;

  for(ii x : m1){
    while(m2.size() > 0 and x.ff + m2.back().ff >= h){
      s.insert(ii(m2.back().ss, key++));
      m2.pop_back();
    }
    int smaller = s.order_of_key(ii(h - x.ss, -1));
    ans += (int)(s.size()) - smaller;
  }
  return ans;
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  for(int i=0; i<t; i++) cout << "Case #" << i+1 << ": " << solve() << endl;
}



