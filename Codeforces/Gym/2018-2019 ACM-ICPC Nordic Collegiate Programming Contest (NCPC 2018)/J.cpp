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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a == 0 && b == 0 && c == 0 && d == 0){
    cout << 0 << endl;
    return 0;
  }
  
  int zero = -1, one = -1;
  for(int i=0; i<112345; i++){
    if((i*(i-1))/2 == a){
      zero = i;
    }
  }
  for(int i=0; i<112345; i++){
    if((i*(i-1))/2 == d){
      one = i;
    }
  }
  if(zero == -1 || one == -1){
    cout << "impossible" << endl;
    return 0;
  }
  if(b == 0 && c == 0 && d == 0) one = 0;
  if(a == 0 && b == 0 && c == 0) zero = 0;
  string ans;
  int cb = 0, cc = 0;
  while(one > 0 || zero > 0){
    //cout << ans << endl;
    if(zero > 0 && cb + one <= b){
      ans += '0';
      zero--;
      cb += one;
    }
    else if(one > 0 && cc + zero <= c){
      ans += '1';
      one--;
      cc += zero;
    }
    else {
      cout << "impossible" << endl;
      return 0;
    }
  }
  if(cb != b || cc != c) cout << "impossible" << endl;  
  else cout << ans << endl;
}
 
