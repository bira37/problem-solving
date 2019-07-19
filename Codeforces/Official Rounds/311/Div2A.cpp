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
  int mn1, mx1, mn2,mx2,mn3,mx3;
  int n;
  cin >> n;
  int ans1 = 0, ans2= 0, ans3= 0;
  cin >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
  while(n > 0 && ans1 < mx1) ans1++, n--;
  while(n > 0 && ans2 < mn2) ans2++, n--;
  while(n > 0 && ans3 < mn3) ans3++, n--;
  while(ans2 < mn2) ans2++, ans1--;
  while(ans3 < mn3) ans3++, ans1--;
  while(n > 0 && ans2 < mx2) ans2++, n--;
  while(n > 0 && ans3 < mx3) ans3++, n--;
  cout << ans1 << " " << ans2 << " " << ans3 << endl;
 
}
 
