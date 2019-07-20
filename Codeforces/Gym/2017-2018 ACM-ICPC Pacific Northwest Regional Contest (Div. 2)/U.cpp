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
  double d[7];
  for(int i=1; i<=6; i++){
    cin >> d[i];
  }
  double ans = INF;
  double sum = 0;
  for(int j = 1; j<=6; j++){
    sum += j*d[j];
  }
  for(int i = 1; i<=6; i++){
    double cur = (3.5 - (sum - d[i]*i))/d[i];
    ans = min(ans, abs(cur - i));
  }
  cout << fixed << setprecision(3) << ans << endl; 
}
 
