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
  
  int  T;
  cin >> T;
  
  for(int t = 0; t < T; t++) {
    int n;
    cin >> n;
    
    int ans = 0;
    double bto = -1e13;
    for(int i = 0; i < n; i++) {
      int a,b,c;
      cin >> a >> b >> c;
      
      double ini = 0, end = 1e13;
      for(int d = 0; d < 200; d++) {
        double q1 = ini+(end-ini)/3;
        double q2 = end-(end-ini)/3;
        double to1 = -a*q1*q1 + b*q1 + c;
        double to2 = -a*q2*q2 + b*q2 + c;        
        if(to2 < to1) {
          end = q2;
        } else {
          ini = q1;
        }
      }
      double to = -a*ini*ini + b*ini + c;
      if(to > bto) {
        ans = i;
        bto = to;
      }
    }
    cout << ans+1 << endl;
  }
}
 
 
 
