#include <bits/stdc++.h>
 
#define int unsigned long long
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
 
int PA(int n){
  return (n*(n+1))/2;
}
 
int triangle(int a, int b){
  return PA(b) - PA(a);
}
 
int solve(int n, int m){
  int ans = 0;
  for(int i=1; i<=m; i++){
    ans += (n/i)*i + PA(max(m, n/i));
  }
  return ans;
}
 
int32_t main(){
  DESYNC;
  
  int a,b;
  cin >> a >> b;
  
  int m = sqrt(b);
  int s = 0;
  for (int f = 1; f <= m; f++){
    int x = (b/f)*(b/f) - max(m, (a-1)/f)*max(m, (a-1)/f) + (b/f) - max(m, (a-1)/f);
    s += f *(b/f - (a-1)/f);
    s += x/2;
  }
  cout << s << endl;
}
