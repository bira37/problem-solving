#include <bits/stdc++.h>
 
#define int long long
#define double long double
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
	ii v[n+1];
	int p[n+1];
	for(int i=1; i<=n; i++){
	  int x;
	  cin >> x;
	  v[i].ff = x;
	  v[i].ss = i;
	}
	sort(v+1, v+n+1, greater<ii>());
	p[0] = 0;
	for(int i=1; i<=n; i++) p[i] = p[i-1] + v[i].ff;
	int k;
	cin >> k;
	int best = (int)1e18;
	int sum = 0, dif = 0;
	int idx = -1;
	for(int i=1; i<=k; i++){
	  sum += v[i].ff*(k-i);
	  dif += v[i].ff*(i-1);
	}
	best = sum - dif;
	idx = 1;
	for(int i = k+1; i<=n; i++){
	  //update
	  sum -= (k-1)*v[i-k].ff;
	  dif += (k-1)*v[i].ff;
	  sum += p[i-1] - p[i-k];
	  dif -= p[i-1] - p[i-k];
	  if(sum - dif < best){
	    best = sum - dif;
	    idx = i-k+1;
	  }
	}
	for(int i=idx; i<idx+k; i++) cout << v[i].ss << " ";
	cout << endl;
}
 
