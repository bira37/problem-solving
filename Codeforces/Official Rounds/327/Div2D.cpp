#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<double, double>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF (int)2e18
#define ROOT 1

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}  

int32_t main(){
	DESYNC;
	ii s, e;
	cin >> s.ff >> s.ss >> e.ff >> e.ss;
	double vmax, t;
	cin >> vmax >> t;
	ii v,w;
	cin >> v.ff >> v.ss >> w.ff >> w.ss;
	
	double l = 0.000000000000, r = 1e9;
	double ans = -1;
	for(int it = 0; it < 200; it++){
	  double m = (l+r)/2.;
	  ii pos;
	  if(m < t){
	    pos.ff = s.ff + v.ff*m;
	    pos.ss = s.ss + v.ss*m;	  
	  }
	  else {
	    pos.ff = s.ff + v.ff*t + w.ff*(m - t);
	    pos.ss = s.ss + v.ss*t + w.ss*(m - t);
	  } 
	  double dist = sqrt((pos.ff - e.ff)*(pos.ff - e.ff) + (pos.ss - e.ss)*(pos.ss - e.ss));
	  if(dist <= vmax*m){
	    ans = m;
	    r = m;
	  }
	  else l = m;
	}
	cout << fixed << setprecision(9) << ans << endl;
}

