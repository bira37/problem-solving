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
 
bool ok(int n){
  if(n == 0) return true;
  if(n < 0) return false;
  
  bool ret = false;
  ret |= ok(n-1234567);
  if(ret) return ret;
  ret |= ok(n-123456);
  if(ret) return ret;
  ret |= ok(n-1234);
  return ret;
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int x = 0; x <= n/1234567; x++){
    for(int y = 0; y <= n/123456; y++){
      int cur = n - x*1234567 - y*123456;
      if(cur >= 0 && cur%1234 == 0){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
