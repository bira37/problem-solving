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
 
struct trade{
  string a,b;
  double q;
};
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  cout << fixed << setprecision(10);
  map<string, double> m;
  trade v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].a >> v[i].b >> v[i].q;
  }
  m["blue"] = 0;
  for(int i=n-1; i>=0; i--){
    if(m.count(v[i].a)){
      if(m.count(v[i].b)) m[v[i].b] = max(m[v[i].b], m[v[i].a] + log10(v[i].q));
      else m[v[i].b] = m[v[i].a] + log10(v[i].q);
    }
  }
  if(m["pink"] == 0) cout << 0 << endl;
  else if(m["pink"] >= 1) cout << 10 << endl;
  else cout << pow(10, m["pink"]) << endl;    
}
 
