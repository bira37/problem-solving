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
  
}
 
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
	
	  double area2(){
		  double area2 = points.back().x*points[0].y - points.back().y*points[0].x;
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
	    
	    if(abs(p.x-upper[0].x) < EPS){
			  if(p.y > upper[0].y){
				  //upper
				  if(abs(upper[1].x - upper[0].x) > EPS) return false;
				  else if(p.y <= upper[1].y) return true;
			  }
			  else {
				  //lower
				  if(abs(lower[1].x - lower[0].x) > EPS) return false;
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
 
////////////////////////////////// End of  Geometry Structures /////////////////////////////
 
vector<Geo2D::Point> v;
 
bool check_inner(int k, double sc){
  vector<Geo2D::Point> points;
  for(int i=0; i<k; i++){
    Geo2D::Point p(sc, 0);
    p.rotate(i*(2*PI/k));
    points.pb(p);
  }
  Geo2D::ConvexHull chull;
  chull.calculate(points);
  for(Geo2D::Point p : v){
    if(chull.insideHull(p)) return false;
  }
  return true;
}
 
bool check_outter(int k, double sc){
  vector<Geo2D::Point> points;
  for(int i=0; i<k; i++){
    Geo2D::Point p(sc, 0);
    p.rotate(i*(2*PI/k));
    points.pb(p);
  }
  Geo2D::ConvexHull chull;
  chull.calculate(points);
  for(Geo2D::Point p : v){
    if(!chull.insideHull(p)) return false;
  }
  return true;
}
 
double area(int k, double sc){
  vector<Geo2D::Point> points;
  for(int i=0; i<k; i++){
    Geo2D::Point p(sc, 0);
    p.rotate(i*(2*PI/k));
    points.pb(p);
  }
  Geo2D::ConvexHull chull;
  chull.calculate(points);
  return chull.area();
}
    
  
double solve(int k){
  double l = 1, r = 1e7;
  
  //inner
  for(int it = 0; it < 200; it++){
    double m = (l+r)/2.;
    
    if(check_inner(k, m)) l = m;
    else r = m;
  }
  double inner_scale = l;
  //outter
  l = 1, r = 1e7;
  
  for(int it = 0; it < 200; it++){
    double m = (l+r)/2.;
    
    if(check_outter(k, m)) r = m;
    else l = m;
  }
  
  double outter_scale = l;
  
  return area(k, inner_scale)/area(k, outter_scale);
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  v.resize(n);
  for(int i=0; i<n; i++){
    cin >> v[i].x >> v[i].y;
  }
  
  double score = 0;
  int ans = -1;
  for(int k=3; k<=8; k++){
    double sc = solve(k);
    if(sc > score){
      score = sc;
      ans = k;
    }
  }
  cout << ans << " " << fixed << setprecision(7) << score << endl;
}
 
