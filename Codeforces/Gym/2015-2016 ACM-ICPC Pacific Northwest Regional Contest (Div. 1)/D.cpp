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
  
  int t1[3];
  int t2[3];
  cin >> t1[0] >> t1[1] >> t1[2];
  cin >> t2[0] >> t2[1] >> t2[2];
  
  
  sort(t1, t1+3);
  sort(t2, t2+3);
  
  for(int i = 0; i < 3; i++) {
    if(t1[i] != t2[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if(t1[0]*t1[0] + t1[1]*t1[1] != t1[2]*t1[2]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
   
}
 
