#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
//#define vi vector<int>
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
 
struct reg {
  int sz; double v;
};
 
vector<reg> rgs;
 
int n, x;
double v;
 
int l[112];
int r[112];
double vi[112];
   
 
double check(double o) {
  //cout << n << endl;
  int i;
  //cout << o << endl;
  for(i = 0; i < n; i++) {
    rgs[i*2].v = v*sin(o);
    rgs[i*2+1].v = v*sin(o) + vi[i];
    //cout << rgs[i*2].sz << " " << rgs[i*2].v << endl;
    //cout << rgs[i*2+1].sz << " " << rgs[i*2+1].v << endl;    
  }
  rgs[i*2].v = v*sin(o);
  //cout << rgs[i*2].sz << " " << rgs[i*2].v << endl;
 
  //cout << endl;
  double vrx = v*cos(o);
  //cout << "vrx " << vrx << endl;
  double y = 0;
  for(reg rg : rgs) {
 
    y += (double)rg.v*rg.sz/vrx; 
    //cout << "y: " <<y << endl;
  }
  //cout << endl << endl;
  
  return fabs(y);
}
 
int32_t main(){
  DESYNC;
   
   cin >> n >> x >> v;
   
   
   for(int i = 0; i < n; i++) {
    cin >> l[i] >> r[i] >> vi[i];
   }
   
   
   int lst = 0;
   for(int i = 0; i < n; i++) {
     rgs.pb({l[i]-lst, v});
     rgs.pb({r[i]-l[i], v});    
     lst = r[i];
    }
    rgs.pb({x-lst, v});
   
   double ini = -acos(-1)/2, end = acos(-1)/2;
   for(int i = 0; i < 200; i++) {
    //cout << "ini: " << ini << " end: " << end << endl;
    double q1 = ini + (abs(end - ini))/3;
    double q2 = ini + 2*(abs(end - ini))/3;
    double a1 = check(q1);
    double a2 = check(q2);
    //cout << "a1: " << q1 << " " << a1 << endl;
    //cout << "a2: " << q2 << " " << a2 << endl;
    //cout << (a2 > a1) << endl;
    //cout << endl << endl;
    if(a2 > a1) end = q2;
    else ini = q1;
   }
   double vrx = v*cos(ini);
   double ti = x/vrx;
   //cout << x << " " << v << endl;
   //cout << ti << endl;
   //cout << x/v << endl;
   double bla = x/v;
   double bla2 = check(ini);
   if(ti > 2*bla || abs(bla2) > 1e-11) {
    cout << "Too hard" << endl;
   } else {
    cout << fixed << setprecision(3) << ti << endl;
   }
}
 
