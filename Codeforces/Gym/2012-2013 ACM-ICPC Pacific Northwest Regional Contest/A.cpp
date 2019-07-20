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
  int t;
  cin >> t;
  for(int it = 1; it<=t; it++){
    cout << "Battle " << it << ":";
    int a,b,c,d,e,f,g;
    cin >> a >> b >> c >> d >> e >> f;
    int ans1 = a + 2*b + 3*c + 3*d + 4*e + 10*f;
    cin >> a >> b >> c >> d >> e >> f >> g;
    int ans2 = a + 2*b + 2*c + 2*d + 3*e + 5*f + 10*g;
    if(ans1 < ans2) cout << " Evil eradicates all trace of Good" << endl;
    else if(ans1 > ans2) cout << " Good triumphs over Evil" << endl;
    else cout << " No victor on this battle field" << endl;
  }
 
}
 
