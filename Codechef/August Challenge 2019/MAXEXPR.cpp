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

struct expr{
  double k, c, x;
  int id;
  expr(){}
  bool operator<(const expr & e) const {
    return k < e.k;
  }
};

void solve(){
  int n;
  cin >> n;
  expr v[n];
  for(int i=0; i<n; i++) v[i].id = i;
  for(int i=0; i<n; i++) cin >> v[i].k;
  for(int i=0; i<n; i++) cin >> v[i].c;
  sort(v, v+n);
  double acc = 0;
  for(int i=1; i<n; i++){
    v[i].x = -v[i].c;
    acc += v[i].x*v[i].k;
  }
  v[0].x = -acc/v[0].k;
  if(v[0].x < -v[0].c){
    cout << -1 << endl;
    return;
  }
  //cout << "initial vals" << endl;
  //for(int i=0; i<n; i++) cout << v[i].x << " ";
  //cout << endl;
  
  //fix 
  sort(v+1, v+n, [](const expr & a, const expr & b){
    return a.k < b.k;
  });
  
  int i = 1;

  double l = 0, r = v[0].x - (-v[0].c);
  for(int iter = 0; iter < 60; iter++){
    
    double m1 = l + (r-l)/3.;
    double m2 = r - (r-l)/3.;
    
    
    double give1 = 0;
    for(int i=1; i<n; i++){
      give1 += m1*(v[1].k/v[i].k);
    }
    if(give1 > v[0].x - (-v[0].c)){
      r = m1;
      continue;
    }
    
    double give2 = 0;
    for(int i=1; i<n; i++){
      give2 += m2*(v[1].k/v[i].k);
    }
    if(give2 > v[0].x - (-v[0].c)){
      r = m2;
      continue;
    }
    
    double f1 = 0.0;
    double f2 = 0.0;
    
    f1 += sqrt(v[0].x + v[0].c - give1);
    f2 += sqrt(v[0].x + v[0].c - give2);
    
    for(int i=1; i<n; i++){
      f1 += sqrt(v[i].x + v[i].c + (v[0].k/v[i].k)*m1*(v[1].k/v[i].k));
      f2 += sqrt(v[i].x + v[i].c + (v[0].k/v[i].k)*m2*(v[1].k/v[i].k));
    }
    
    if(f1 < f2) l = m1;
    else if(f1 > f2) r = m2;
    else if(f1 == f2) l = m1;
    
  }
  
  //cout << l << endl;
  
  double give = 0;
  for(int i=1; i<n; i++){
    give += l*(v[1].k/v[i].k);
  }  

  v[0].x -= give;
  for(int i=1; i<n; i++){
    v[i].x += (v[0].k/v[i].k)*l*(v[1].k/v[i].k);
  }
  
  sort(v, v+n, [](const expr & a, const expr & b){
    return a.id < b.id;
  });
  double ans = 0.0;
  double ans2 = 0.0;
  for(int i=0; i<n; i++){
    ans += sqrt(v[i].x + v[i].c);
    ans2 += v[i].x*v[i].k;
  }
  cout << fixed << setprecision(5) << ans; 
  for(int i=0; i<n; i++) cout << " " << v[i].x;
  cout << endl;
}

int32_t main(){
  DESYNC;
  int t;
  cin >> t;
  while(t--) solve();
}
