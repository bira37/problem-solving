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
 
struct guy{
  double x,y;
  string nick;
  guy() {}
  guy(double x, double y, string nick) : x(x), y(y), nick(nick) {}
};
 
vector<guy> v;
 
vector< guy > MERGESORT(vector< guy > v, double S, int eita){
  //getchar();
  if(v.size() <= 1){
    if(v.size() == 1) cout << v[0].nick << endl;
    return v;
  }
  
  vector< guy > fst,scd,thrd, frth;
  
  for(guy & g : v){
    
    if(g.x < 0 && g.y < 0) fst.pb(g);
    else if(g.x < 0 && g.y > 0) scd.pb(g);
    else if(g.x > 0 && g.y > 0) thrd.pb(g);
    else frth.pb(g);
  }
  
  //first quadrant
  for(guy & g : fst){
    g.x += S/4.;
    g.y += S/4.;
    double nx = g.x*cos(PI/2) - g.y*sin(PI/2);
    double ny = g.x*sin(PI/2) + g.y*cos(PI/2);
    g.x = -nx;
    g.y = ny;
  }
  
  MERGESORT(fst, S/2., 1);
  
  //second
  for(guy & g : scd){
    g.x += S/4.;
    g.y -= S/4.;
  }
  
  MERGESORT(scd, S/2., 2);
  
  //third
  
  for(guy & g : thrd){
    g.x -= S/4.;
    g.y -= S/4.;
  }
  
  MERGESORT(thrd, S/2., 3);
  
  //fourth
  
  for(guy & g : frth){
    g.x -= S/4.;
    g.y += S/4.;
    double nx = g.x*cos(PI/2) + g.y*sin(PI/2);
    double ny = -g.x*sin(PI/2) + g.y*cos(PI/2);
    g.x = -nx;
    g.y = ny;
  }
  
  MERGESORT(frth, S/2., 4);
  
  vector< guy > ans;
  for(guy g : fst) ans.pb(g);
  for(guy g : scd) ans.pb(g);
  for(guy g : thrd) ans.pb(g);
  for(guy g : frth) ans.pb(g);
  return ans;
}
 
int32_t main(){
  //DESYNC;
  int n;
  double S;
  cin >> n >> S;
  v.resize(n);
  for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y >> v[i].nick;
  for(guy & g : v){
    g.x -= S/2.;
    g.y -= S/2.;
  }
  v = MERGESORT(v, S, -1);
  //for(guy g : v) cout << g.nick << endl;
}
 
