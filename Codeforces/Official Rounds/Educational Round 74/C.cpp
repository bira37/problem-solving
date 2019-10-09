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
  int q;
  cin >> q;
  while(q--){
    int h,n;
    cin >> h >> n;
    vector<int> v(n);
    cin >> v[0];
    for(int i=0; i<n-1; i++) cin >> v[i];
    v[n-1] = 0;
    int ans = 0;
    for(int i=0; i<n-1; i++){
      int cur = v[i]+1;
      if(v[i] - v[i+1] > 1){
        ans++;
      }
      else i++;
    }
    cout << ans << endl;
  }
}
