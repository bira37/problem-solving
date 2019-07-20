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
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
using namespace __gnu_pbds;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct team{
  int id, sc, p;
  team () {}
  team(int id, int sc, int p) : id(id), sc(sc), p(p) {}
  bool operator<(const team & b) const {
    return sc > b.sc || (sc == b.sc && p < b.p) || (sc == b.sc && p == b.p && id < b.id);
  }
};
 
typedef tree<
team,
null_type,
less< team >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
int32_t main(){
  DESYNC;
  ordered_set s;
  int n,m;
  cin >> n >> m;
  int score[n+1];
  int penalty[n+1];
  for(int i=1; i<=n; i++){
    s.insert(team(i, 0, 0));
    score[i] = 0;
    penalty[i] = 0;
  }
  while(m--){
    int t, p;
    cin >> t >> p;
    auto it = s.lower_bound(team(t, score[t], penalty[t]));
    team cur = *it;
    s.erase(it);
    score[t]++;
    penalty[t]+=p;
    s.insert(team(t, score[t], penalty[t]));
    it = s.lower_bound(team(0, score[1], penalty[1]));
    cout << s.order_of_key(*it) + 1 << endl;
  }
}
 
