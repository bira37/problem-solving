#include <bits/stdc++.h>
#define pii pair<double, double>
#define ff first
#define ss second
 
using namespace std;
 
double check(double m, pii * v, int n){
	double max = 0.0;
	for(int i=0; i<n; i++){
		max = std::max(max, (m-v[i].ff)*(m-v[i].ff) + v[i].ss*v[i].ss);
	}
	return max;
}
 
int main() {
	int n, max;
	cin >> n >> max;
	pii v[n];
	for(int i=0; i<n; i++) cin >> v[i].ff >> v[i].ss;
 
	double l=0.0, r=max;
	while(r - l > 1e-6){
		double m1 = (2*l+r)/3;
		double m2 = (l + 2*r)/3;
		if(check(m1, v, n) < check(m2, v, n)) r = m2;
		else l = m1;
	}
	cout << fixed << setprecision(2);
	cout << l << " " << sqrt(check(l,v,n)) << endl;
	return 0;
}
