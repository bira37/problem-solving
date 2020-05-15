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

int32_t main(){
  DESYNC;
  int n,m;
  cin >> n >> m;
  int g[n][m+1];
  for(int i=0; i<n;i++){
    for(int j=0; j<=m; j++){
      cin >> g[i][j];
    }
  }
  set<int> s;
  for(int i=0; i<n; i++) s.insert(g[i][0]);
  if(s.size() == 1){
    cout << *s.begin() << " " << 0 << endl;
    return 0;
  }
  //simulate m+1 times
  for(int it=1; it<=m+1; it++){
    s.clear();
    for(int i=0; i<n; i++){
      g[i][0] = g[i][g[i][0]];
      s.insert(g[i][0]);
    }
    if(s.size() == 1){
      cout << *s.begin() << " " << it << endl;
      return 0;
    }
  }
  int ans[m+1];
  for(int i=0; i<=m; i++) ans[i] = -1;
  int sz[n];
  int cnt[m+1];
  for(int i=0; i<=m; i++) cnt[i] =0;
  for(int i=0; i<n; i++){
    int cur = g[i][g[i][0]];
    sz[i] = 1;
    cnt[g[i][0]]++;
    while(cur != g[i][0]){
      cnt[cur]++;
      sz[i]++;
      cur = g[i][cur];
    }
  }
  for(int x = 1; x <= m; x++){
    if(cnt[x] != n) continue; 
    vector<int> a(n), k(n);
    for(int i=0; i<n; i++){
      k[i] = sz[i];
      if(x == g[i][0]) a[i] = 0;
      else {
        int cur = g[i][g[i][0]];
        a[i] = 1;
        while(cur != x){
          a[i]++;
          cur = g[i][cur];
        }
      }
    }
    int ret, md;
    tie(ret, md) = NT::CRT(a, k);
    if(NT::FailCRT) continue;
    else ans[x] = ret;
  }
  int prt = -1;
  for(int i=1; i<=m; i++) {
    if(ans[i] == -1) continue;
    if(prt == -1 || ans[i] < ans[prt]) prt = i;
  }
  if(prt == -1) cout << "*" << endl;
  else cout << prt << " " << m+1+ans[prt] << endl;        
}


