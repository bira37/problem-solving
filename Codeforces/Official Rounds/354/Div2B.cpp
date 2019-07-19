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
  int n,t ;
  cin >> n >> t;
  
  vector< vector<int> > v;
  for(int i =0; i<n; i++){
    v.pb(vector<int>(i+1));
  }
  v[0][0] = t*1024;
  for(int i=0; i<n; i++){
    for(int j=0; j<v[i].size(); j++){
      int tira = max(0LL, v[i][j] - 1024);
      //cout << i << " " << j << " " << v[i][j] << " " << tira << endl;
      v[i][j] -= tira;
      if(i+1 < n) v[i+1][j] += tira/2;
      if(i+1 < n) v[i+1][j+1] += tira/2;
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    for(int x : v[i]){
      if(x >= 1024) ans++;
    }
  }
  cout << ans << endl;
}
 
