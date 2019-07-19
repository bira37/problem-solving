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
 
struct ingr{
  int n,q,p;
  ingr(){}
  ingr(int n ,int q, int p) : n(n), q(q), p(p) {}
};
 
bool cmp(const ingr & a, const ingr & b){
  return a.n/a.q <= b.n/b.q;
}
 
int32_t main(){
	DESYNC;
	string ss;
	int b=0,s=0,c=0;
	int ans = 0;
	cin >> ss;
	for(char ccc : ss){
	  if(ccc == 'B') b++;
	  else if(ccc == 'S') s++;
	  else if(ccc == 'C') c++;
	}
	int nb,ns,nc;
	cin >> nb >> ns >> nc;
	int pb, ps, pc;
	cin >> pb >> ps >> pc;
	int k;
	cin >> k;
	if(b == 0) nb = 1000000000000000, b = 1;
	if(c == 0) nc = 1000000000000000, c = 1;
	if(s == 0) ns = 1000000000000000, s = 1;
	int can_now = min(nb/b, min(ns/s, nc/c));
	ans += can_now;
	nb -= b*can_now;
	nc -= c*can_now;
	ns -= s*can_now;
	vector< ingr > v;
	if(b > 0) v.pb(ingr(nb, b, pb));
	else v.pb(ingr(1000000000000000, 1, 1000000000000000));
	if(c > 0) v.pb(ingr(nc, c, pc));
	else v.pb(ingr(1000000000000000, 1, 1000000000000000));
	if(s > 0) v.pb(ingr(ns, s, ps));
	else v.pb(ingr(1000000000000000, 1, 1000000000000000));
	sort(v.begin(), v.end(), cmp);
	//cout << ans << " " << k << endl;
	//try to build sand buying one ingredient
  int can = v[1].n/v[1].q;
  int bought = 0;
  if(abs(v[0].q - v[0].n)*v[0].p <= k){
    bought++;
    can--;
    k -= abs(v[0].q - v[0].n)*v[0].p;
    v[0].n = 0;
  }
  int can_buy = k/(v[0].q*v[0].p);
  can_buy = min(can_buy, can);
  bought += can_buy;
  v[1].n -= bought*v[1].q;
  v[2].n -= bought*v[2].q;
  k -= (v[0].q*v[0].p)*can_buy;
  ans += bought;
  if(v[1].n >= v[1].q){
    cout << ans << endl;
    return 0;
  }
  //cout << ans << " " << k << endl;
  //try to build sand buying two ingredient
  can = v[2].n/v[2].q;
  bought = 0;
  if(abs(v[1].q - v[1].n)*v[1].p + v[0].p*v[0].q <= k){
    bought++;
    can--;
    k -= abs(v[1].q - v[1].n)*v[1].p + v[0].p*v[0].q;
    v[1].n = 0;
  }
  can_buy = k/(v[0].q*v[0].p + v[1].q*v[1].p);
  can_buy = min(can_buy, can);
  bought += can_buy;
  v[2].n -= bought*v[2].q;
  k -= abs(v[0].q*v[0].p + v[1].q*v[1].p)*can_buy;
  ans += bought;
  if(v[2].n >= v[2].q){
    cout << ans << endl;
    return 0;
  }
  //cout << ans << " " << k << endl;
  //try to build sand buying all three
  if(abs(v[2].q - v[2].n)*v[2].p + v[0].p*v[0].q + v[1].q*v[1].p <= k){
    ans++;
    k -= abs(v[2].q - v[2].n)*v[2].p + v[0].p*v[0].q + v[1].q*v[1].p;
    v[2].n = 0;
  }
  ans += k/(v[0].p*v[0].q + v[1].q*v[1].p + v[2].p*v[2].q);
  cout << ans << endl;
}
 
