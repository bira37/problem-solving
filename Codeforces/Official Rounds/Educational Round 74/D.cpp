#include <bits/stdc++.h>
 
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
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  s = '0' + s;
  for(int i=1; i<=n; i++){
    if(s[i] != s[i-1]) v.pb(1);
    else v.back()++;
  }
  int ans = 0;
  for(int i=1; i<v.size(); i++){
    ans += v[i-1];
    ans += v[i];
    ans -= 1;
  }
  //cout << ans << endl;
  cout << (n*(n-1))/2 - ans << endl;
}
