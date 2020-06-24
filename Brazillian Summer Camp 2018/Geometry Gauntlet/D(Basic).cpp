#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point2d{
	ll x,y;
};

int main(){
	Point2d a,b,c;
	double cx,cy,r;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	double p1 = sqrt((a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y));
	double p2 = sqrt((a.x - c.x)*(a.x - c.x) + (a.y-c.y)*(a.y-c.y));
	double p3 = sqrt((b.x - c.x)*(b.x - c.x) + (b.y-c.y)*(b.y-c.y));
	double p = p1+p2+p3;
	cx = (double)(a.x*p3 + b.x*p2 + c.x*p1)/p;
	cy = (double)(a.y*p3 + b.y*p2 + c.y*p1)/p;
	
	ll vx = b.x - a.x;
	ll vy = b.y - a.y;
	
	ll eqa = b.y - a.y;
	ll eqb = a.x - b.x;
	ll eqc = eqa*a.x + eqb*a.y;
	r = abs(eqa*cx + eqb*cy - eqc)/sqrt(eqa*eqa + eqb*eqb);
	cout << fixed << setprecision(15) << cx << " " << cy << " " << r << endl;
}
