#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
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
    
    //shifts solution
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
      //cerr << "here boy " << i << endl;
      int x,y;
      tie(x,y) = ExtendedEuclidean(modulo, n[i]);
      int g = GCD(modulo, n[i]);
      
      if(g == 0 || (a[i] - ans)%g != 0){
        FailCRT = true;
        return make_tuple(0,0);
      }
      
      ans = mod(ans + (x*((a[i] - ans)/g))%(n[i]/g) * modulo, modulo*(n[i]/g));
      modulo = modulo*(n[i]/g);
    }
    
    return make_tuple(ans, modulo); 
  }

}

void solve(int n, int m){
  vector<int> a, mods;
  for(int k : {16, 9, 5, 7, 11, 13, 17}){
    for(int j=0; j<18; j++){
      if(j > 0) cout << " ";
      cout << k;
    }
    cout << endl;
    int sum = 0;
    for(int j=0; j<18; j++){
      int x;
      cin >> x;
      if(x == -1) exit(0);
      sum += x;
      sum %= k;
    }
    a.pb(sum); mods.pb(k);
  }
  int val, md;
  tie(val, md) = NT::CRT(a, mods);
  cout << val << endl;
  int res;
  cin >> res;
  if(res != 1) exit(0);
}

int32_t main(){
  int t, n, m;
  cin >> t >> n >> m;
  for(int i=1; i<=t; i++) solve(n, m);
}


