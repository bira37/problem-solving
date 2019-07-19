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
 
int check(int n){
	int ans= 0;
	for(int i=2; i*i*i<=n; i++){
		ans += n/(i*i*i);
	}
	return ans;
}
 
int32_t main(){
  DESYNC;
  int x;
  cin >> x;
 	int l = 1, r = (int)1e16;
 	int ans = -1;
 	while(l <= r){
 		int m = (l+r)>>1;
 		int got = check(m);
 		if(got == x){
 			ans = m;
 			r = m -1;
 		}
 		else if(got >= x){
 			r = m-1;
 		}
 		else l = m+1;
 	}
 	cout << ans << endl;
}
 
