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
#define MOD 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int32_t main(){
  
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  
  string x;
  
  cin >> x;
  int n = x.size();
  
  int ans = 1;
  for(int i = 0; i < n-1; i++) {
    if(x[i] == 'N') {
      if(x[i+1] == 'W') {
        ans*= 2;
       } else if(x[i+1] == 'E') {
        ans*=2;
       } 
     } else if(x[i] == 'S') {
      if(x[i+1] == 'W') {
        ans*= 2;
       } else if(x[i+1] == 'E') {
        ans*=2;
       } 
     }
    
    ans %= MOD;
  }
  
  
  
  cout << ans << endl;
  
}
 
