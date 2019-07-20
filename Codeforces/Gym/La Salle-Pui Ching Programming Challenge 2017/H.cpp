#include <bits/stdc++.h>
#define point pair<double,double>
#define x first
#define y second
using namespace std;
 
double dist(point p, point a){
	return (p.x - a.x)*(p.x - a.x) + (p.y - a.y)*(p.y - a.y);
}
 
bool inside(point p, point a, point b, double a_rad, double b_rad){
	double da = dist(p, a);
	double db = dist(p, b);
	return (da <= a_rad*a_rad && db <= b_rad*b_rad);
}
 
int main(){
	int n;
	point a, b;
	double a_rad, b_rad;
	cin >> a.x >> a.y >> a_rad;
	cin >> b.x >> b.y >> b_rad;
 
	point vec(b.x - a.x, b.y - a.y);
 
	double test = 0.00000;
	for(int i = 0; i<10000000; i++, test += 0.00001){
		point p(a.x + test*vec.x, a.y + test*vec.y);
		if(inside(p, a, b, a_rad, b_rad)){
			cout << fixed << setprecision(8) << p.x << " " << p.y << endl;
			return 0;
		}
	}
}
