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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

struct Point2D {
  double x,y;
  
  Point2D(){
    x = 0;
    y = 0;
  }
  
  Point2D(double x, double y) : x(x), y(y) {}
  
  Point2D operator+(const Point2D & b){
    return Point2D(x + b.x, y + b.y);
  }
  
  Point2D operator-(const Point2D & b){
    return Point2D(x - b.x, y - b.y);
  }
  
  bool operator<(const Point2D & b){
    return x < b.x || (x == b.x && y < b.y);
  }
  
  void operator=(const Point2D & b){
    x = b.x;
    y = b.y;
  }
  
  double distanceTo(Point2D & b){
    return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
  }
  
  double distanceTo2(Point2D & b){
    return (x - b.x)*(x - b.x) + (y - b.y)*(y - b.y);
  }
  
};

struct Vector2D {
  double x,y;
  
  Vector2D(){
    x = 0;
    y = 0;
  }
  
  Vector2D(double x, double y) : x(x), y(y) {}
  
  Vector2D(Point2D a, Point2D b){
    x = b.x - a.x;
    y = b.y - a.y;
  }
  
  Vector2D operator+(const Vector2D & b){
    return Vector2D(x + b.x, y + b.y);
  }
  
  Vector2D operator-(const Vector2D & b){
    return Vector2D(x - b.x, y - b.y);
  }
  
  void operator=(const Vector2D & b){
    x = b.x;
    y = b.y;
  }
  
  double operator*(const Vector2D & b){
    return (x*b.x + y*b.y);
  }
  
  double operator^(const Vector2D & b) {
		return x*b.y - y*b.x;
	}
	
	bool operator<(const Vector2D & b){
		return x < b.x || (x == b.x && y < b.y);
	}
	
	Vector2D scale(double n){
	  return Vector2D(x*n, y*n);
	}
	
	double size(){
	  return sqrt(x*x + y*y);
	}
	
	double size2(){
	  return x*x + y*y;
	}
	
	Vector2D normalize(){
	  return Vector2D(x/size(), y/size());
	}
	
};

struct Line2D {
  Point2D p;
  Vector2D v;
  Vector2D normal;
  
  double a,b,c;
  
  Line2D() {
    p = Point2D();
    v = Vector2D();
    normal = Vector2D();
    a = 0;
    b = 0;
    c = 0;
  }
  
  void operator=(const Line2D & l){
    a = l.a;
    b = l.b;
    c = l.c;
    p = l.p;
    v = l.v;
    normal = l.normal;
  }
  
  Line2D(Point2D r, Point2D s){
    p = r;
    v = Vector2D(r, s);
    normal = Vector2D(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
  Line2D(Point2D r, Vector2D s){
    p = r;
    v = s;
    normal = Vector2D(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
};

struct Segment2D {
  Point2D p, q;
  Vector2D v;
  Vector2D normal;
  
  double a,b,c;
  
  Segment2D() {
    p = Point2D();
    q = Point2D();
    v = Vector2D();
    normal = Vector2D();
    a = 0;
    b = 0;
    c = 0;
  }
  
  void operator=(const Segment2D & l){
    a = l.a;
    b = l.b;
    c = l.c;
    p = l.p;
    q = l.q;
    v = l.v;
    normal = l.normal;
  }
  
  Segment2D(Point2D r, Point2D s){
    p = r;
    q = s;
    v = Vector2D(r, s);
    normal = Vector2D(-v.y, v.x);
    a = -v.y;
    b = v.x;
    c = -(a*p.x + b*p.y);
  }
  
};

double distancePointSegment(Point2D & p, Segment2D & l){
  double dot1 = Vector2D(l.p, p)*Vector2D(l.p, l.q);
  double dot2 = Vector2D(l.q, p)*Vector2D(l.q, l.p);
  
  if(dot1 >= 0 && dot2 >= 0) return (1.*abs(l.a*p.x + l.b*p.y + l.c))/l.normal.size();
  else return min(p.distanceTo(l.p), p.distanceTo(l.q));
}

double distancePointLine(Point2D & p, Line2D & l){
  return (1.*abs(l.a*p.x + l.b*p.y + l.c))/l.normal.size();
}

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	vector< Point2D > g(n);
	double sumx = 0.0, sumy = 0.0;
	for(int i=0; i<n; i++){
	  double x,y;
	  cin >> x >> y;
	  g[i] = Point2D(x,y);
	  sumx += x;
	  sumy += y;
	}
	Point2D ans(sumx/n, sumy/n);
	
	//check if inside
	int m;
	cin >> m;
	vector< Point2D > hull(m);
	for(int i=0; i<m; i++){
	  double x,y;
	  cin >> x >> y;
	  hull[i] = Point2D(x,y);
	}
	bool inside = true;
	for(int i=0; i<m; i++){
	  Point2D cur = hull[i];
	  Point2D nxt = hull[(i+1)%m];
	  Vector2D v1(ans, nxt), v2(ans, cur);
	  if((v1^v2) < 0) inside = false;
	}
	if(inside){
	  double sum = 0;
	  for(int i=0; i<n; i++) sum += ans.distanceTo2(g[i]);
	  cout << fixed << setprecision(9) << sum << endl;
	  return 0;
	}
	
	Segment2D best;
	double dist = 1e18;
	
	for(int i=0; i<m; i++){
	  Point2D cur = hull[i];
	  Point2D nxt = hull[(i+1)%m];
	  Segment2D s(cur, nxt);
	  double d = distancePointSegment(ans, s);
	  if(d < dist){
	    dist = d;
	    best = s;
	  }
	}
	Vector2D u = best.v.normalize();
  Vector2D w(best.p, ans);
  Vector2D res = u.scale(u*w);
  if(u*w < 0 || u*w > best.p.distanceTo(best.q)){
    if(ans.distanceTo(best.p) < ans.distanceTo(best.q)) ans = best.p;
    else ans = best.q;
  }
  else ans = Point2D(best.p.x + res.x, best.p.y + res.y);
    
	double sum = 0;
	for(int i=0; i<n; i++) sum += ans.distanceTo2(g[i]);
	cout << fixed << setprecision(9) << sum << endl;
	
}