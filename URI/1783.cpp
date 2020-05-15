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

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
};

struct line {
  double a,b,c;
};

int32_t main(){
  DESYNC;
  int q = 0;
  int n;
  cin >> n;
  while(q++ < n){
    point a,b,c,d;
    cin >> a.x >> a.y >> c.x >> c.y >> b.x >> b.y >> d.x >> d.y;

    point m1((a.x + b.x)/2., (a.y + b.y)/2.);
    point m2((c.x + d.x)/2., (c.y + d.y)/2.);

    point v1(b.x-a.x, b.y-a.y);
    point v2(d.x-c.x, d.y-c.y);

    point inv_v1(-v1.y, v1.x);
    point inv_v2(-v2.y, v2.x);

    line l1, l2;
    l1.a = -inv_v1.y;
    l1.b = inv_v1.x;
    l1.c = -(l1.a*m1.x + l1.b*m1.y);

    l2.a = -inv_v2.y;
    l2.b = inv_v2.x;
    l2.c = -(l2.a*m2.x + l2.b*m2.y);

    double x, y;
    if(abs(l1.c*l2.b - l2.c*l1.b) <= EPS or abs(l1.a*l2.b - l2.a*l1.b) <= EPS) x = 0;
    else x = -(l1.c*l2.b - l2.c*l1.b)/(l1.a*l2.b - l2.a*l1.b);
    if(abs(l1.a*l2.c - l2.a*l1.c) <= EPS or abs(l1.a*l2.b - l2.a*l1.b) <= EPS) y = 0;
    else y = -(l1.a*l2.c - l2.a*l1.c)/(l1.a*l2.b - l2.a*l1.b);
    cout << fixed << setprecision(2) << "Caso #" << q << ": " << x << " " << y << endl;
  }
}



