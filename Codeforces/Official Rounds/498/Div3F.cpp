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
 
map< tuple<int,int,int>, int> cu1, cu2;
int mat[23][23];
int n,m,k;
int walk;
map<tuple<int,int,int>,  int> A;
int ans = 0;
 
void go(int i, int j, int val, int step){
	if(step == walk){
		A[mt(i,j,val)]++;
		return;
	}
	if(i+1 < n) go(i+1, j, val^mat[i+1][j], step+1);
	if(j+1 < m) go(i, j+1, val^mat[i][j+1], step+1);
}
 
void solve(int i, int j, int val, int step){
	if(step == walk){
		ans += A[mt(i,j, val^k^mat[i][j])];
		return;
	}
	if(i-1 >= 0) solve(i-1, j, val^mat[i-1][j], step+1);
	if(j-1 >= 0) solve(i, j-1, val^mat[i][j-1], step+1);
}
 
int32_t main(){
  DESYNC;
  cin >> n >> m >> k;
  for(int i=0; i<n; i++){
  	for(int j=0; j<m; j++) cin >> mat[i][j];
  }
  walk = (n+m)/2;
  go(0,0, mat[0][0], 1);
  walk = (n+m) - (n+m)/2;
  solve(n-1, m-1, mat[n-1][m-1], 1); 
  cout << ans << endl;
}
 
