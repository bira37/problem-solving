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

//////////////////////////////////  Geometry Structures ////////////////////////////////////

namespace Geo2D {
 
  struct Point {
    int x,y;
    
    Point(){
      x = 0;
      y = 0;
    }
    
    Point(int x, int y) : x(x), y(y) {}
    
    Point(Point a, Point b){
      x = b.x - a.x;
      y = b.y - a.y;
    }
    
    Point operator+(const Point b) const{
      return Point(x + b.x, y + b.y);
    }
    
    Point operator-(const Point b) const{
      return Point(x - b.x, y - b.y);
    }
    
    int operator*(const Point b) const{
      return (x*b.x + y*b.y);
    }
    
    int operator^(const Point b) const{
      return x*b.y - y*b.x;
    }
  
    Point scale(int n){
      return Point(x*n, y*n);
    }
    
    void operator=(const Point b) {
      x = b.x;
      y = b.y;
    }
    
    bool operator==(const Point b){
      return x == b.x && y == b.y;
    }
    
    double distanceTo(Point b){
      return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
    }
    
    int squareDistanceTo(Point b){
      return (x - b.x)*(x - b.x) + (y - b.y)*(y - b.y);
    }
    
    bool operator<(const Point & p) const{
      return tie(x,y) < tie(p.x, p.y);
    }
    
    double size(){
      return sqrt(x*x + y*y);
    }
  
    int squareSize(){
      return x*x + y*y;
    }
  
    //Only with double type
    Point normalize(){
      return Point((double)x/size(), (double)y/size());
    }
  
    void rotate(double ang){
      double xx = x, yy = y;
      x = xx*cos(ang) + yy*-sin(ang);
      y = xx*sin(ang) + yy*cos(ang);
    }
    
  };

  struct Line {
    Point p, q;
    Point v;
    Point normal;
    
    int a,b,c;
    
    Line() {
      p = Point();
      q = Point();
      v = Point();
      normal = Point();
      a = 0;
      b = 0;
      c = 0;
    }
    
    Line(int aa, int bb, int cc){
      a = aa;
      b = bb;
      c = cc;
      normal = Point(a,b);
      v = Point(-normal.y, normal.x);
      p = Point();
      q = Point();
    }
    
    void operator=(const Line l){
      a = l.a;
      b = l.b;
      c = l.c;
      p = l.p;
      q = l.q;
      v = l.v;
      normal = l.normal;
    }
    
    Line(Point r, Point s){
      p = r;
      q = s;
      v = Point(r, s);
      normal = Point(-v.y, v.x);
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
    
    bool operator<(const Line & l) const{
      return tie(a,b,c) < tie(l.a, l.b, l.c);
    }
    
  };

  struct Circle{
    Point c;
    double r;
    Circle() {}
    Circle(Point center, double radius) : c(center), r(radius) {}
    
    bool operator=(Circle circ){
      c = circ.c;
      r = circ.r;
    }
    
    pair<Point, Point> getTangentPoints(Point p){
      //p needs to be outside the circle
      double d = p.distanceTo(c);
      double ang = asin(1.*r/d);
      Point v1(p, c);
      v1.rotate(ang);
      Point v2(p, c);
      v2.rotate(-ang);
      v1 = v1.scale(sqrt(d*d - r*r)/d);
      v2 = v2.scale(sqrt(d*d - r*r)/d);
      Point p1(v1.x + p.x, v1.y + p.y);
      Point p2(v2.x + p.x, v2.y + p.y);
      return make_pair(p1,p2);
    }
    
    double sectorArea(double ang){
      return (ang*r*r)/2.;
    }
    
    double arcLength(double ang){
      return ang*r;
    }
    
    double sectorArea(Point p1, Point p2){
      double h = p1.distanceTo(p2);
      double ang = acos(1. - h*h/r*r);
      return sectorArea(ang);
    }
    
    double arcLength(Point p1, Point p2){
      double h = p1.distanceTo(p2);
      double ang = acos(1. - (h*h)/(2*r*r));
      return arcLength(ang);
    }
    
    bool inside(const Point & p){
      if(Point(c,p).size() + EPS < r) return true;
      else if(r + EPS < Point(c,p).size()) return false; 
      else return true;
    }
    
  };
  
}

////////////////////////////////// End of  Geometry Structures /////////////////////////////

namespace Geo2D {

  struct ConvexHull {

    vector< Point > points, lower, upper;
    
    ConvexHull(){}
    
    void calculate(vector<Point> v){
      sort(v.begin(), v.end());
      for(int i=0; i<v.size(); i++){
        while(upper.size() >= 2 && (Point(upper[upper.size()-2], upper.back())^Point(upper.back(), v[i])) >= 0LL) upper.pop_back();
        upper.push_back(v[i]);
      }
      reverse(v.begin(), v.end());
      for(int i=0; i<v.size(); i++){
        while(lower.size() >= 2 && (Point(lower[lower.size()-2], lower.back())^Point(lower.back(), v[i])) >= 0LL) lower.pop_back();
        lower.push_back(v[i]);
      }
      for(int i=upper.size()-2; i>=0; i--) points.push_back(upper[i]);
      for(int i=lower.size()-2; i>=0; i--) points.push_back(lower[i]);
      reverse(lower.begin(), lower.end());
    }
  
    double area(){
      double area = points.back().x*points[0].y - points.back().y*points[0].x;
      for(int i=0; i<points.size()-1; i++){
        area += points[i].x*points[i+1].y - points[i].y*points[i+1].x;
      }
      return area/2.;
    }
  
    int area2(){
      int area2 = points.back().x*points[0].y - points.back().y*points[0].x;
      for(int i=0; i<points.size()-1; i++){
        area2 += points[i].x*points[i+1].y - points[i].y*points[i+1].x;
      }
      return area2;
    }
  
    double perimeter(){
      double val = Point(points[0], points.back()).size();
      for(int i=0; i<points.size()-1; i++){
        val += Point(points[i], points[i+1]).size();
      }
      return val;
    }
    
    bool insideHull(Point p){
    
      auto it = lower_bound(lower.begin(), lower.end(),  p);
      if(it != lower.end() && *it == p) return true;
      it = lower_bound(upper.begin(), upper.end(), p);
      if(it != upper.end() && *it == p) return true;
      
      if(p.x == upper[0].x){
        if(p.y > upper[0].y){
          //upper
          if(upper[1].x != upper[0].x) return false;
          else if(p.y <= upper[1].y) return true;
        }
        else {
          //lower
          if(lower[1].x != lower[0].x) return false;
          else if(p.y >= lower[1].y) return true;
        }
        return false;
      }
      Point v1,v2;
      //upper or lower
      int ansu = -1, ansl = -1;
      int l = 0, r = upper.size()-2;
      while(l <= r){
        int m = (l+r)>>1LL;
        if(upper[m].x < p.x && p.x <= upper[m+1].x){
          ansu = m;
          break;
        }
        else if(upper[m+1].x < p.x) l = m+1;
        else r = m-1;
      }
      l = 0, r = lower.size()-2;
      while(l <= r){
        int m = (l+r)>>1LL;
        if(lower[m].x < p.x && p.x <= lower[m+1].x){
          ansl = m;
          break;
        }
        else if(lower[m+1].x < p.x) l = m+1;
        else r = m-1;
      }
      if(ansu == -1 || ansl == -1) return false;
      bool oku = false, okl = false;
      v1 = Point(upper[ansu], upper[ansu+1]);
      v2 = Point(upper[ansu], p);
      oku = ((v1^v2) <= 0);
      v1 = Point(lower[ansl], lower[ansl+1]);
      v2 = Point(lower[ansl], p);
      okl = ((v1^v2) >= 0);
      if(oku && okl) return true;
      else return false;
    }

  };
  
}

int32_t main(){
  DESYNC;
  vector<Geo2D::Point> p;
  int n,d;
  cin >> n >> d;
  p.pb(Geo2D::Point(0, d));
  p.pb(Geo2D::Point(d, 0));
  p.pb(Geo2D::Point(n, n-d));
  p.pb(Geo2D::Point(n-d, n));
  
  Geo2D::ConvexHull chull;
  chull.calculate(p);
  int m;
  cin >> m;
  while(m--){
    Geo2D::Point p;
    cin >> p.x >> p.y;
    if(chull.insideHull(p)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

