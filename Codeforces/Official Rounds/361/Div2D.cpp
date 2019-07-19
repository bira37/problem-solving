#include <bits/stdc++.h>
 
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
#define INF 2e9
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
ii st[812345];
 
int a[212345], b[212345];
void build(int cur, int l, int r){
	if(l == r){
		st[cur] = ii(a[l], b[l]);
		return;
	}
	int m = (l+r)>>1;
	build(2*cur, l, m);
	build(2*cur+1, m+1, r);
	st[cur].ff = max(st[2*cur].ff, st[2*cur+1].ff);
	st[cur].ss = min(st[2*cur].ss, st[2*cur+1].ss);
}
 
ii qry(int cur, int l, int r, int a, int b){
	if(b < l || r < a) return ii(-INF, INF);
	if(a <= l && r <= b) return st[cur];
	int m = (l+r)>>1;
	ii lef = qry(2*cur, l, m, a, b);
	ii rig = qry(2*cur+1, m+1, r, a, b);
	return ii(max(lef.ff, rig.ff), min(lef.ss, rig.ss));
}
 
int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  build(1, 0, n-1);
  long long cnt = 0;
  for(int i=0; i<n; i++){
  	int l = i, r = n-1;
  	int ansr = -1;
  	while(l <= r){
  		int m = (l+r)>>1;
  		ii val = qry(1, 0, n-1, i, m);
  		int max_q = val.ff;
  		int min_q = val.ss;
  		//cout << i << " " << max_q << " " << min_q << " " << m << endl;
  		if(max_q == min_q){
  			ansr = m;
  			l = m+1;
  		}
  		else if(max_q > min_q){
  			r = m-1;
  		}
  		else l = m+1;
  	}
  	l = i, r = n-1;
  	int ansl = -1;
  	while(l <= r){
  		int m = (l+r)>>1;
  		ii val = qry(1, 0, n-1, i, m);
  		int max_q = val.ff;
  		int min_q = val.ss;
  		//cout << i << " " << max_q << " " << min_q << " " << m << endl;
  		if(max_q == min_q){
  			ansl = m;
  			r = m-1;
  		}
  		else if(max_q > min_q){
  			r = m-1;
  		}
  		else l = m+1;
  	}
  	if(ansl != -1 && ansr != -1) cnt += max(0, ansr - ansl+1);
  	//cout << ansl << " " << ansr << " " << i << endl;
  }
  cout << cnt << endl;
}
 
