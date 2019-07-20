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
 
vector<int> grf[(int) 3e5+1];
 
int32_t main(){
  DESYNC;
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; ++i){
    int a, b;
    cin >> a >> b;
    grf[a].pb(b);
    grf[b].pb(a);
  }
  bool guards[n];
  memset(guards, -1, sizeof(guards));
  int men=1;
  for(int i=2; i<=n; ++i){
    if(grf[i].size()<grf[men].size())
      men=i;
  }
  guards[men-1]=false;
  for(auto i : grf[men])
    guards[i-1]=false;
  for(int i=0; i<n; ++i){
    if(i)
      cout << ' ';
    if(guards[i])
      cout << 1;
    else cout << 0;
  }
  cout << endl;
}
 
