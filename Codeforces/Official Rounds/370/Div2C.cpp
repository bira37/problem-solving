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
  int x,y;
  cin >> x >> y;
  swap(x,y);
  vector<int> v(3);
  v[0] = v[1] = v[2] = x;
  int ans = 0;
  while(v[0] != y || v[1] != y || v[2] != y){
    int want = min(v[1] + v[2]-1, y);
    v[0] = want;
    sort(v.begin(), v.end());
    ans++;
    //cout << v[0] << " " << v[1] << " " << v[2] << endl;
  } 
  cout << ans << endl;
}
 
