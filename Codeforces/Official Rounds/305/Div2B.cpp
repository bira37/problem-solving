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
bool mat[500][500];
int n,m;
int ans[500];

set< ii, greater<ii> > s;
int query(int x){
  int ans = 0;
  int cur = 0;
  for(int j = 0; j<m; j++){
    if(mat[x][j]) cur++;
    else {
      ans = max(ans, cur);
      cur = 0;
    }
  }
  ans = max(ans, cur);
  return ans;
}
int32_t main(){
	DESYNC;
	int q;
	cin >> n >> m >> q;
	for(int i=0; i<n; i++){
	  for(int j=0; j<m; j++) cin >> mat[i][j];
	}
	int mx = 0;
	for(int i=0; i<n; i++){
	  ans[i] = query(i);
	  s.insert(ii(ans[i], i));
	}
	while(q--){
	  int x,y;
	  cin >> x >> y;
	  x--, y--;
	  mat[x][y] = !mat[x][y];
	  s.erase(s.find(ii(ans[x], x)));
	  ans[x] = query(x);
	  s.insert(ii(ans[x], x));
	  cout << s.begin()->ff << endl;
	}
}