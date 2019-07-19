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
  else return __gcd(a,b);
}
 
int32_t main(){
	DESYNC;
	
	int t;
	cin >> t;
	while(t--){
	  int n,g;
	  cin >> n >> g;
	  int sum = g;
	  for(int i = 1; i < n; i++) {
	     int x;
	     cin >> x;
	     sum += x;
	     g = gcd(g, x);
	  }
	  
	  cout << sum << " " << g << endl;
	}
}
