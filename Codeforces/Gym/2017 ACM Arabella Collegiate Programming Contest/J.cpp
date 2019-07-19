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
  else return __gcd(a,b);
}
 
struct Point2D {
  double x,y;
  
  Point2D(){
    x = 0;
    y = 0;
  }
  
  Point2D(double x, double y) : x(x), y(y) {}
  
  Point2D operator+(const Point2D b) const{
    return Point2D(x + b.x, y + b.y);
  }
  
  Point2D operator-(const Point2D b) const{
    return Point2D(x - b.x, y - b.y);
  }
  
  bool operator<(const Point2D b) const{
    return x < b.x || (x == b.x && y < b.y);
  }
  
  void operator=(const Point2D b) {
    x = b.x;
    y = b.y;
  }
  
  double distanceTo(Point2D b){
    return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
  }
  
  double distanceTo2(Point2D b){
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
  
  double operator*(const Vector2D b) const{
    return (x*b.x + y*b.y);
  }
  
  double operator^(const Vector2D b) const{
		return x*b.y - y*b.x;
	}
	
	bool operator<(const Vector2D b) const{
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
	  return Vector2D((double)x/size(), (double)y/size());
	}
	
};
 
int32_t main(){
	DESYNC;
	int t;
	cin >> t;
	while(t--){
	  double r, a;
	  cin >> r >> a;
	  double ang = (a*PI)/180.0;
	  Vector2D v1(0, r), v2(0*cos(ang) + r*-sin(ang), 0*sin(ang) + cos(ang)*r);
	  cout << fixed << setprecision(9) << endl;
	  cout << (r*r*ang - (v1^v2))/2.0 << endl;
	} 
}
