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
#define N 212345

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int uf[N];
int sz[N];

int find(int u){ 
  if(u == uf[u]) return u;
  else return uf[u] = find(uf[u]);
}

void merge(int u, int v){
  int a = find(u);
  int b = find(v);
  if(rand()%2) swap(a,b);
  uf[a] = b;
  sz[b] += sz[a];
}

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	vector< ii > v;
	int ans[n+1];
	for(int i=0; i<=n; i++) ans[i] = -1;
	for(int i=0; i<n; i++){
	  int x;
	  cin >> x;
	  v.pb(ii(x, i));
	}
	sort(v.begin(), v.end(), greater< ii >());
	for(int i=0; i<n; i++){
	  uf[i] = i;
	  sz[i] = 0;
	}
	for(ii p : v){
	  int x = p.ff;
	  int i = p.ss;
	  //cout << "at (" << x << ", " << i << ")" << endl; 
	  if(sz[i] == 0) sz[i] = 1;
	  if(i - 1 >= 0 && sz[find(i-1)] > 0) merge(i-1, i);
	  if(i+1 < n  && sz[find(i+1)] > 0) merge(i, i+1);
	  //cout << "updating ans for sz " << sz[find(i)] << endl;
	  if(ans[sz[find(i)]] == -1) ans[sz[find(i)]] = x;
  }
  //for(int i=1; i<=n; i++) cout << ans[i] << " ";
  //cout << endl;
  for(int i=n-1; i>=1; i--) ans[i] = max(ans[i], ans[i+1]);
  for(int i=1; i<=n; i++) cout << ans[i] << " ";
  cout << endl;	  
}