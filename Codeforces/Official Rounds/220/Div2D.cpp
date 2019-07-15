#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const double PI = acos(-1);

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

typedef tree<
ii,
null_type,
less< ii >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int32_t main(){
  DESYNC;
  ordered_set s;
  int n,m;
  cin >> n >> m;
  int v[m];
  for(int i=0; i<m; i++) cin >> v[i];
  for(int it = 0; it < n; it++){
    int x;
    cin >> x;
    if(x == 0 || x == 1) s.insert(ii(it, x));
    else {
      vector< ordered_set::iterator > to_del;
      for(int i=0; i<m; i++){
        if(s.size() < v[i]) break;
        to_del.pb(s.find_by_order(v[i]-1));
      }
      for(auto it : to_del){
        s.erase(it);
      }
    }
  }
  string ans = "";
  for(auto x : s) ans +=  to_string(x.ss);
  if(ans == "") cout << "Poor stack!" << endl;
  else cout << ans << endl;
}