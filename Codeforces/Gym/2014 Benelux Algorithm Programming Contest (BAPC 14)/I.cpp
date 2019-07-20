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
 
namespace NT{
 
  int GCD(int a, int b){
    if(a == 0) return b;
    else return GCD(b%a, a);
  }
  
  tuple<int,int> ExtendedEuclidean(int a, int b){
    //solves ax+by = gcd(a,b)
    //careful when a or b equal to 0
    if(a == 0) return make_tuple(0,1);
    int x,y;
    tie(x,y) = ExtendedEuclidean(b%a, a);
    return make_tuple(y - (b/a)*x, x);
  }
  
  bool FailDiophantine = false;
  
  tuple<int,int> Diophantine(int a, int b, int c){
    FailDiophantine = false;
    //finds a solution for ax+by = c
    //given a solution (x,y), all solutions have the form (x + m*(b/gcd(a,b)), y - m*(a/(gcd(a,b))), multiplied by (c/g)
    
    int g = GCD(a,b);
    
    if(g == 0 || c%g != 0) {
      FailDiophantine = true;
      return make_tuple(0,0);
    }
    
    int x,y;
    
    tie(x,y) = ExtendedEuclidean(a, b);
    int s1 = x*(c/g), s2 = y*(c/g);
    
    int l = 0, r = 1e9;
    int ans = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(s2 + m*(a/g) >= 0){
        ans = m;
        r = m-1;
      }
      else l = m+1;
    }
    if(ans != -1){
      s1 = s1 - ans*(b/g);
      s2 = s2 + ans*(a/g);
    }
    
    l = 0, r = 1e9;
    ans = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(s1 + m*(a/g) >= 0){
        ans = m;
        r = m-1;
      }
      else l = m+1;
    }
    if(ans != -1){
      s1 = s1 + ans*(b/g);
      s2 = s2 - ans*(a/g);
    }
    
    l = 0, r = 1e9;
    ans = -1;
    while(l <= r){
      int m = (l+r)>>1;
      if(s1 - m*(a/g) <= s2 + m*(b/g)){
        ans = m;
        r = m-1;
      }
      else l = m+1;
    }
    if(ans != -1){
      s1 = s1 - ans*(b/g);
      s2 = s2 + ans*(a/g);
    }
    
    return make_tuple(s1, s2);
  }
  
  bool FailCRT = false;
  
  tuple<int,int> CRT(vector<int> & a, vector<int> & n){
    FailCRT = false;
    for(int i=0; i<a.size(); i++) a[i] = mod(a[i], n[i]);
    int ans = a[0];
    int modulo = n[0];
    
    for(int i=1; i<a.size(); i++){
      int x,y;
      tie(x,y) = ExtendedEuclidean(modulo, n[i]);
      int g = GCD(modulo, n[i]);
      
      if(g == 0 || (a[i] - ans)%g != 0){
        FailCRT = true;
        return make_tuple(0,0);
      }
      
      ans = mod(ans + (x*(a[i] - ans)/g)%(n[i]/g) * modulo, modulo*n[i]/g);
      modulo = modulo*n[i]/g;
    }
    
    return make_tuple(ans, modulo); 
  }
 
}
 
int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  int f[46];
  f[0] = 0;
  f[1] = 1;
  f[2] = 2;
  for(int i=3; i<=45; i++) f[i] = f[i-1] + f[i-2];
  while(t--){
    int n;
    cin >> n;
    int ansa, ansb;
    ansa = n/2, ansb = n - n/2;
    for(int i=3; i<=45; i++){
      //suppose it is the i-th term of gib sequence define as n = f(i-1)*B + f(i-2)*A
      int a,b;
      //cout << i << " " << f[i-2] << " " << f[i-1] << " " << n << endl;
      tie(a,b) = NT::Diophantine(f[i-2], f[i-1], n);
      //cout << "with " << n << " equal to " << i << "th term ans is " << a << " " << b << endl;
      if(NT::FailDiophantine) continue;
      if(a <= 0 || b <= 0) continue;
      if(a > b) continue;
      if(b < ansb || (b == ansb && a < ansa)){
        ansa = a;
        ansb = b;
      }
    }
    cout << ansa << " " << ansb << endl;
  }
}
 
