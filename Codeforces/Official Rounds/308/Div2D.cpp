#include <bits/stdc++.h>
 
#define int long long
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
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
struct Point2D {
  int x,y;
  
  Point2D(){
    x = 0;
    y = 0;
  }
  
  Point2D(int x, int y) : x(x), y(y) {}
  
  Point2D operator+(const Point2D b) const{
    return Point2D(x + b.x, y + b.y);
  }
  
  Point2D operator-(const Point2D b) const{
    return Point2D(x - b.x, y - b.y);
  }
  
  void operator=(const Point2D b) {
    x = b.x;
    y = b.y;
  }
  
  double distanceTo(Point2D b){
    return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
  }
  
  int squareDistanceTo(Point2D b){
    return (x - b.x)*(x - b.x) + (y - b.y)*(y - b.y);
  }
  
  bool operator<(const Point2D & p) const{
    return tie(x,y) < tie(p.x, p.y);
  }
  
};
 
struct Vector2D {
  int x,y;
  
  Vector2D(){
    x = 0;
    y = 0;
  }
  
  Vector2D(int x, int y) : x(x), y(y) {}
  
  Vector2D(Point2D a, Point2D b){
    x = b.x - a.x;
    y = b.y - a.y;
  }
  
  Vector2D operator+(const Vector2D b) const{
    return Vector2D(x + b.x, y + b.y);
  }
  
  Vector2D operator-(const Vector2D b) const{
    return Vector2D(x - b.x, y - b.y);
  }
  
  void operator=(const Vector2D b) {
    x = b.x;
    y = b.y;
  }
  
  int operator*(const Vector2D b) const{
    return (x*b.x + y*b.y);
  }
  
  int operator^(const Vector2D b) const{
		return x*b.y - y*b.x;
	}
	
	bool operator<(const Vector2D & v) const{
    return tie(x,y) < tie(v.x, v.y);
  }
	
	Vector2D scale(int n){
	  return Vector2D(x*n, y*n);
	}
	
	double size(){
	  return sqrt(x*x + y*y);
	}
	
	int squareSize(){
	  return x*x + y*y;
	}
	
	//Only with double type
	Vector2D normalize(){
	  return Vector2D((double)x/size(), (double)y/size());
	}
	
	Vector2D rotate(double ang){
	  return Vector2D(x*cos(ang) + y*-sin(ang), x*sin(ang) + y*cos(ang));
	}
	
};
 
struct Line2D {
  Point2D p, q;
  Vector2D v;
  Vector2D normal;
  
  int a,b,c;
  
  Line2D() {
    p = Point2D();
    q = Point2D();
    v = Vector2D();
    normal = Vector2D();
    a = 0;
    b = 0;
    c = 0;
  }
  
  void operator=(const Line2D l){
    a = l.a;
    b = l.b;
    c = l.c;
    p = l.p;
    q = l.q;
    v = l.v;
    normal = l.normal;
  }
  
  Line2D(Point2D r, Point2D s){
    p = r;
    q = s;
    v = Vector2D(r, s);
    normal = Vector2D(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
  Line2D(Point2D r, Vector2D s){
    p = r;
    q = Point2D(p.x + s.x, p.y + s.y);
    v = s;
    normal = Vector2D(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
  void flip_sign(){
    a = -a, b = -b, c = -c;
  }
  
  void normalize(){
    if(a < 0) flip_sign();
    else if(a == 0 && b < 0) flip_sign();
    else if(a == 0 && b == 0 && c < 0) flip_sign();
    int g = max(a, max(b,c));
    if(a != 0) g = gcd(g, a); if(b != 0) g = gcd(g,b); if(c != 0) g = gcd(g,c);
    if(g > 0) a/=g, b/=g, c/=g;
  }
  
  bool operator<(const Line2D & l) const{
    return tie(a,b,c) < tie(l.a, l.b, l.c);
  }
  
};
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  Point2D v[n];
  for(int i=0; i<n; i++){
    cin >> v[i].x >> v[i].y;
  }
  int ans = (n*(n-1)*(n-2))/6;
  for(int i=0; i<n; i++){
    map<Line2D, int > m;
    for(int j=i+1; j<n; j++){
      Line2D l(v[i], v[j]);
      l.normalize();
      m[l]++;
    }
    for(auto k : m){
      int val = k.second;
      ans -= val*(val-1)/2;
    }
  }
  cout << ans << endl;  
} 
