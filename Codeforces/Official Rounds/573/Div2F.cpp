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
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}

typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int keys = 1;
set< ii > points;
ordered_set s;


int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  map<int, vector<int> > m;
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    points.insert(ii(x,y));
    m[-y].pb(x);
  }
  int ans = 0;
  for(auto p : m){
    sort(p.ss.begin(), p.ss.end());
    ans += p.ss.size();
    for(int x : p.ss) s.insert(x);
    int lst = -1;
    for(int i=0; i<p.ss.size(); i++){
      int lst;
      if(i+1 == p.ss.size()) lst = (int)(1e9)+10;
      else lst = p.ss[i+1];
      int x = p.ss[i];
      int k1 = s.order_of_key(x+1);
      int k2 = s.order_of_key(lst )- s.order_of_key(x);
      ans += (k1*k2-1LL);
    }
  }
  cout << ans << endl;
}

