#include <bits/stdc++.h>
 
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
	
	int t;
	scanf("%d", &t);
	while(t--){
	  int n,ms;
	  scanf("%d%d", &n, &ms);
	  map<string, double> m;
	  for(int i=0; i<n; i++){
	    string s;
	    char ss[10];
	    double d;
	    scanf("%s", ss);
	    scanf("%lf", &d);
	    s = string(ss);
	    m[s] = d;
	  }
	  m["JD"] = 1;
	  double amm = 0.0;
	  for(int i=0; i<ms; i++){
	    double d;
	    string s;
	    char ss[10];
	    scanf("%lf", &d);
	    scanf("%s", ss);
	    s = string(ss);
	    amm += m[s]*d;
	  }
	  cout << fixed << setprecision(9) << amm << endl;
	}
}
 
