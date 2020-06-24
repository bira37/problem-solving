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
    double x,y;
    
    Point(){
      x = 0;
      y = 0;
    }
    
    Point(double x, double y) : x(x), y(y) {}
    
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
    
    double operator*(const Point b) const{
      return (x*b.x + y*b.y);
    }
    
    double operator^(const Point b) const{
		  return x*b.y - y*b.x;
	  }
	
	  Point scale(double n){
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
    
    double squareDistanceTo(Point b){
      return (x - b.x)*(x - b.x) + (y - b.y)*(y - b.y);
    }
    
    bool operator<(const Point & p) const{
      return tie(x,y) < tie(p.x, p.y);
    }
    
    double size(){
	    return sqrt(x*x + y*y);
	  }
	
	  double squareSize(){
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

////////////////////////////////// Geometry  Algorithms ////////////////////////////////////

namespace Geo2D {
  
  Point barycenter(Point & a, Point & b, Point & c, double pA, double pB,  double pC){
    Point ret = (a.scale(pA) + b.scale(pB) + c.scale(pC));
    ret.x /= (pA + pB + pC);
    ret.y /= (pA + pB + pC);
    return ret;
  }
  
  Point circumcenter(Point & a, Point & b, Point & c){
    double pA = Point(b,c).squareSize(), pB = Point(a,c).squareSize(), pC = Point(a,b).squareSize();
    return barycenter(a,b,c, pA*(pB+pC-pA), pB*(pC+pA-pB), pC*(pA+pB-pC));
  }
  
  Circle minimumCircle(vector<Point> & v){
    Circle circ(Point(0,0), 1e-14);
    random_shuffle(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
      if(!circ.inside(v[i])){
        circ = Circle(v[i], 0);
        for(int j=0; j<i; j++){
          if(!circ.inside(v[j])){
            circ = Circle((v[i] + v[j]).scale(0.5), Point(v[i], v[j]).size()*0.5);
            for(int k = 0; k<j; k++){
              if(!circ.inside(v[k])){
                Point center = circumcenter(v[i], v[j], v[k]);
                circ = Circle(center, Point(center, v[k]).size());
              }
            }
          }
        }
      }
    }
    return circ;
  }
  
}

////////////////////////////////// End of Geometry  Algorithms /////////////////////////////

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  vector<Geo2D::Point> v(n);
  for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
  Geo2D::Circle circ = Geo2D::minimumCircle(v);
  cout << fixed << setprecision(11) << circ.c.x << " " << circ.c.y << endl << circ.r << endl;
}


