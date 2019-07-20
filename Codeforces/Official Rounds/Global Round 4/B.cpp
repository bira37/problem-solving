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
  string s;
  cin >> s;
  int p[s.size()+1];
  int n = s.size();
  p[0] = 0;
  p[1] = 0;
  for(int i=2; i<=n; i++) p[i] = p[i-1] + (s[i-1] == 'v' && s[i-2] == 'v');
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(s[i-1] !=  'o') continue;
    ans += ((p[i-1]))*((p[s.size()] - p[i]));
  }
  cout << ans << endl;
}
 
