#include <bits/stdc++.h>
 
//#define int long long
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
 
int bit[1123456];
 
void update(int x, int v, int n){
  for(int i = x; i <= n; i += (i&-i)){
    bit[i] ^= v;
  }
}
 
int prefix(int x){
  int ans = 0;
  for(int i=x; i>0; i -= (i&-i)){
    ans ^= bit[i];
  }
  return ans;
}
 
int query(int l, int r){
  return prefix(r)^prefix(l-1);
}
 
map<int, vector<int>> lst;
 
struct _query{
  int l, r, id;
  bool operator<(const _query & q) const{
    return r > q.r;
  }
};
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int v[n+1];
  v[0] = 0;
  int arr[n+1];
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    arr[i] = x;
    v[i] = v[i-1]^x;
    if(lst[x].size() > 0) update(lst[x].back(), x, n);
    lst[x].pb(i);
    update(lst[x].back(), x, n);
  }
  int k;
  cin >> k;
  vector< _query > q(k);
  int ans[k];
  for(int i=0; i<k; i++){
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q.begin(), q.end());
  int pointer = n;
  for(_query qry : q){
    int l = qry.l;
    int r = qry.r;
    int id = qry.id;
    while(pointer > 0 && pointer > r){
      int x = arr[pointer];
      update(lst[x].back(), x, n);
      lst[x].pop_back();
      if(lst[x].size() > 0) update(lst[x].back(), x, n);
      pointer--;
    }
    //cout << query(1, 1, n, l, r) << endl;
    int val = query(l, r)^(v[r]^v[l-1]);
    ans[id] = val;
  }
  for(int i=0; i<k; i++) cout << ans[i] << endl;
}
 
