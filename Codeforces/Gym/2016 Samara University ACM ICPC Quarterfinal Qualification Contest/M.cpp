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
 
int32_t main(){
  DESYNC;
  vector<int> v;
  int n;
  cin >> n;
  vector<int> f[n];
  for(int i=0; i<n; i++){
    v.pb(i);
  }
  
  while(v.size() > 1){
    vector<int> new_v;
    for(int i=0; i<v.size(); i+=2){
      int j1 = v[i];
      if(i+1 < v.size()){
        int j2 = v[i+1];
        cout << "? " << j1+1 << " " << j2+1 << endl;
        cout.flush();
        char c;
        cin >> c;
        if(c == '>'){
          f[j1].pb(j2);
          new_v.pb(j1);
        }
        else {
          f[j2].pb(j1);
          new_v.pb(j2);
        }
      }
      else {
        new_v.pb(j1);
      }
    }
    v = new_v;
  }
  int winner = v[0];
  int ans = f[winner][0];
  for(int i=1; i<f[winner].size(); i++){
    cout << "? " << ans+1 << " " << f[winner][i]+1 << endl;
    cout.flush();
    char c;
    cin >> c;
    if(c == '<') ans = f[winner][i];
  }
  cout << "! " << ans+1 << endl;
  cout.flush();
}
 
