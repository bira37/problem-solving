#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define ff first
#define ss second
 
using namespace std;
 
pii v[61234];
 
bool check(double t, int n){
	double l;
	double r;
	l = v[0].ff-v[0].ss*t;
	r = v[0].ff+v[0].ss*t;
	for(int i=1; i<n; i++){
		l = max(l, v[i].ff - v[i].ss*t);
		r = min(r, v[i].ff + v[i].ss*t);
	}
	if(l <= r) return true;
	return false;
}
 
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i].ff;
	}
	for(int i=0; i<n; i++){
		cin >> v[i].ss;
	}
	double l = 0.0;
	double r = 1e9;
	
	for(int i=0; i<60; i++){
		if(r - l < 1e-6) break;
		double m = (l+r)/2;
		if(check(m,n)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(12);
	cout << r << endl;
	
}
