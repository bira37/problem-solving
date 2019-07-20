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
 
struct Event{
  int t, id;
  int w, c;
  Event() {}
  Event(int id, int t, int w, int c) : id(id), t(t), w(w), c(c) {}
  bool operator<(const Event & e) const{
    return w > e.w || (w == e.w && t < e.t);
  }
};
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int ans[n+1];
  vector<Event> event;
  for(int i=0; i<n; i++){
    int w,c;
    cin >> w >> c;
    event.pb(Event(i+1, 2, w, c));
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    int w,c;
    cin >> w >> c;
    event.pb(Event(i+1, 1, w, c));
  }
  sort(event.begin(), event.end());
  
  set< ii > axes;
  
  for(Event e : event){
    if(e.t == 1){
      axes.insert(ii(e.c, e.id));
    }
    else {
      auto it = axes.lower_bound(ii(e.c, -1));
      if(it == axes.end()){
        cout << -1 << endl;
        return 0;
      }
      ans[e.id] = it->second;
      axes.erase(it);
    }
  }
  for(int i=1; i<=n; i++) cout << ans[i] << " ";
  cout << endl;
}
 
