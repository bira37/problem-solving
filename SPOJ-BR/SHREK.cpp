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
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

pair<double,double> v[112345];
int n;
double vc,vs;
double x,y;

double dist(pair<double,double> a, pair<double,double> b){
  double dst = (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
  return sqrt(dst);
}

bool check(double t){
  double tm = t;
  int pos = 0;
  double cover = 0.0;
  for(int i=1; i<n; i++){
    if(dist(v[i-1], v[i])/vc < t){
      //cout << i << " " << dist(v[i-1], v[i]) << " " << dist(v[i-1], v[i])/vc << endl; 
      pos = i;
      cover += dist(v[i-1], v[i])/vc;
      t -= dist(v[i-1], v[i])/vc;
    }
    else break;
  }
  //cout << pos << endl;
  if(pos == n-1 && t <= 1e-7) return false;
  else if(pos == n-1){
    if(dist(v[n-1], make_pair(x,y))/vs <= cover) return true;
    else return false;
  }
  
  double vx = v[pos+1].ff - v[pos].ff;
  double vy = v[pos+1].ss - v[pos].ss;
  double norm = sqrt((vx*vx)+(vy*vy));
  vx /= norm;
  vy /= norm;
  
  double px = v[pos].ff + vx*t*vc;
  double py = v[pos].ss + vy*t*vc;
  return dist(make_pair(x,y), make_pair(px,py))/vs <= tm;
}

int32_t main(){
  DESYNC;
  cin >> n;
  cin >> x >> y;
  for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
  cin >> vs  >> vc;
  double l = 0.0, r = 1e12;
  bool good = false;
  for(int it = 0; it < 200; it++){
    double m = (l+r)/2.;
    if(check(m)){
      r = m;
      good = true;
    }
    else l = m;
  }
  if(!good) cout << "impossivel" << endl;
  else cout << fixed << setprecision(2) << l << endl;
}


