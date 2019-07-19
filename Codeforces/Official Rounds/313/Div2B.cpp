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
  int a1,b1,a2,b2,a3,b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
  if(a1 >= a2 + a3 && b1 >= max(b2,b3)) cout << "YES" << endl;
  else if(b1 >= b2 + b3 && a1 >= max(a2,a3)) cout << "YES" << endl;
  else if(a1 >= b2 + a3 && b1 >= max(a2, b3)) cout << "YES" << endl;
  else if(b1 >= a2 + b3 && a1 >= max(b2,a3)) cout << "YES" << endl;
  else if(a1 >= a2 + b3 && b1 >= max(b2,a3)) cout << "YES" << endl;
  else if(b1 >= b2 + a3 && a1 >= max(a2,b3)) cout << "YES" << endl;
  else if(a1 >= b2 + b3 && b1 >= max(a2,a3)) cout << "YES" << endl;
  else if(b1 >= a2 + a3 && a1 >= max(b2,b3)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
 
