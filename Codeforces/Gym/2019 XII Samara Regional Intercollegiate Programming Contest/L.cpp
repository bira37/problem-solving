#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
 
double dist(ii a, ii b){
	double ret = (a.ff - b.ff)*(a.ff - b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
	return sqrt(ret);
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	double x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if(x1 > x2){
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}
	double R = (r1 + r2 - dist(ii(x1,y1), ii(x2,y2)))/2.;
	
	double Vx = x2 - x1, Vy = y2 - y1;
	double weight = sqrt(Vx*Vx + Vy*Vy);
	Vx /= weight;
	Vy /= weight;
	double k = r1 - R;
	Vx *= k;
	Vy *= k;
	double X = Vx + x1;
	double Y = Vy + y1;
	cout << fixed << setprecision(10) << X << " " << Y << " " << R << endl;
}
