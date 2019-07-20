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
int m, n;
double r;
int ax,ay,bx,by;
 
double solve(int rin) {
  double ans = r*(abs(ay-rin))/(double)n;
  ans += r*(abs(by-rin))/(double)n;
  
  double rr = r*rin/n;
  ans += (PI*rr) * (double)(abs(ax-bx)) / ((double)m);
  return ans;
}
 
int32_t main(){
	DESYNC;
	
	cin >> m >> n >> r;
  cin >> ax >> ay >> bx >> by;
 
  double ans = INF;
  for(int i = 0; i <= n; i++) {
    ans = min(ans, solve(i));
  }
  
  cout << fixed << setprecision(10) << ans << endl;
}
 
