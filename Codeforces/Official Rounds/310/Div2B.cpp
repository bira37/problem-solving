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
  else return abs(__gcd(a,b));
}
 
int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	int v[n];
	bool ok = false;
	for(int i=0; i<n; i++){
	  cin >> v[i];
	}
	for(int it=0; it<=n; it++){
	  for(int i=0; i<n; i++){
	    if(i%2 == 0) v[i] = (v[i]+1)%n;
	    else v[i] = ((v[i]-1)%n + n)%n;
	  }
	  int want = 0;
	  for(int i=0; i<n; i++) if(v[i] == want) want++;
	  if(want == n) ok = true;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
 
