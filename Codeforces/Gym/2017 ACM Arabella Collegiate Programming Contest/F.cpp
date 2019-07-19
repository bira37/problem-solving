#include <bits/stdc++.h>
 
#define int long long
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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
struct Event{
  int l, r, x, t;
  Event() {}
  Event(int l, int r, int x, int t) : l(l), r(r), x(x), t(t) {}
  bool operator<(const Event & b){
    return l < b.l || (l == b.l && t < b.t);
  }
};
 
struct comparator_r{
  bool operator()(const Event & a, const Event & b) const {
    return a.r < b.r || (a.r == b.r && a.t < b.t);
  }
};
 
struct comparator_t{
  bool operator()(const Event & a, const Event & b) const {
    return a.t > b.t;
  }
};
int cnt[112345];
int32_t main(){
	DESYNC;
	int t;
	cin >> t;
	while(t--){
	  int n, q;
	  cin >> n >> q;
	  vector<Event> v(q);
	  for(int i=0; i<q; i++){
	    int id, x, k;
	    cin >> id >> x >> k;
	    v[i].l = max(1LL, id-k);
	    v[i].r = min(n, id+k);
	    v[i].t = i;
	    v[i].x = x;
	    //cout << "segment " << v[i].l << ", " << v[i].r << " -> " << v[i].x << endl;
	  }
	  set< Event, comparator_r > sr;
	  set< Event, comparator_t > st;
    sort(v.begin(), v.end());
    int p = 0;
    int ans = 0;
    for(int i=0; i<112345; i++) cnt[i] = 0;
    for(int i=1; i<=n; i++){
      //cout << "it " << i << endl;
      while(p < v.size() && v[p].l <= i){
        sr.insert(v[p]);
        st.insert(v[p]);
        cnt[v[p].x]++;
        p++;
      }
      while(sr.size() > 0 && sr.begin()->r < i){
        Event it = *sr.begin();
        sr.erase(sr.begin());
        st.erase(st.find(it));
        cnt[it.x]--;
      }
      bool ok = true;
      if(st.size() > 0){
        Event it = *st.begin();
        if(cnt[it.x] == 1) ok = false;
      }
      if(ok) ans++;
    }
    cout << ans << endl;
  }
}
 
