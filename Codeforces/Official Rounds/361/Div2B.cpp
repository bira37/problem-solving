#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
vector<int> g[212345];
int dst[212345];
	
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
  	dst[i] = INF;
  	int x;
  	cin >> x;
  	if(i-1 >= 1) g[i].pb(i-1);
  	if(i+1 <= n) g[i].pb(i+1);
  	g[i].pb(x);
  }
  dst[1] = 0;
  queue< ii > q;
  q.push(ii(1,dst[1]));
  while(!q.empty()){
  	ii p = q.front();
  	int d = p.ss;
  	int u = p.ff;
  	q.pop();
  	if(d != dst[u]) continue;
  	for(int v : g[u]){
  		if(dst[v] > dst[u] + 1){
  			dst[v] = dst[u] + 1;
  			q.push(ii(v, dst[v]));
  		}
  	}
  }
  for(int i=1; i<=n; i++){
  	cout << dst[i] << " ";
  }
	cout << endl;
  
}
 
