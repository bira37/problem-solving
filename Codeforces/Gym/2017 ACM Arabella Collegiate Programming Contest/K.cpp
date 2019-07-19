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
 
using namespace std;
 
inline int mod(int n){ return (n%1000000007); }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}
 
int32_t main(){
	DESYNC;
	
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
	  int r, a;
	  cin >> r >> a;
	  
	  double v1x = 0;
	  double v1y = r;
	  
	  double rad = (double)a*acos(-1)/180.0;
	  
	  double v2x = v1x*cos(rad) + v1y*-sin(rad);
	  double v2y = v1x*sin(rad) + v1y*cos(rad);
	  
	  double ta = abs(v1x*v2y - v1y*v2x) / 2.0;
	  double pa = acos(-1)*(double)r*(double)r*(double)a/360.0;
	  cout << fixed << setprecision(10) << pa - ta << endl;
	}
}
 
