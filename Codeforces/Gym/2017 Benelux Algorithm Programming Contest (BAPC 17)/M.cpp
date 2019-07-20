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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct LIS{
  vector<int> seq;
 
  void calculate(vector<int> & v){
    int n = v.size();
    seq.resize(n+1);
	  for(int i=1; i<=n; i++) seq[i] = INF;
	  seq[0] = -INF;
	  for(int i=0; i<n; i++){
		  int index = upper_bound(seq.begin(), seq.end(), v[i]) - seq.begin();
		  index--;
		  seq[index+1] = min(seq[index+1], v[i]);
	  }
  }
} lis; 
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  ii st,ed;
  cin >> st.ff >> st.ss >> ed.ff >> ed.ss;
  int f1 = 1, f2 = 1;
  if(st.ff > ed.ff) f1*=-1;
  if(st.ss > ed.ss) f2*=-1;
  st.ff *= f1;
  st.ss *= f2;
  ed.ff *= f1;
  ed.ss *= f2;
  vector< ii > v;
  for(int i=0; i<n; i++){
    ii x;
    cin >> x.ff >> x.ss;
    x.ff *= f1;
    x.ss *= f2;
    if(x.ff < st.ff || x.ff > ed.ff || x.ss < st.ss || x.ss > ed.ss) continue;
    //cout << "pushing " << x.ff << " " << x.ss << endl;
    v.pb(x);
  }
  sort(v.begin(), v.end());
  vector<int> a;
  for(ii x : v) a.pb(x.ss);
  lis.calculate(a);
  int ans = 0;
  for(int i=0; i<lis.seq.size(); i++) if(lis.seq[i] != INF) ans = max(ans, i);
  cout << ans << endl;
}
 
