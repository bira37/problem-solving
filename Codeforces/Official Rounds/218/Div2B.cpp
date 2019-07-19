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
	int a,b;
	cin >> a >> b;
	int cnt2[2], cnt3[2], cnt5[2];
	cnt2[0] = cnt2[1] = cnt3[0] = cnt3[1] = cnt5[0] = cnt5[1] = 0;
	while(a % 2 == 0){
	  cnt2[0]++;
	  a /= 2;
	}
	while(a % 3 == 0){
	  cnt3[0]++;
	  a /= 3;
	}
	while(a % 5 == 0){
	  cnt5[0]++;
	  a /= 5;
	}
	while(b % 2 == 0){
	  cnt2[1]++;
	  b /= 2;
	}
	while(b % 3 == 0){
	  cnt3[1]++;
	  b /= 3;
	}
	while(b % 5 == 0){
	  cnt5[1]++;
	  b /= 5;
	}
	if(a != b){
	  cout << -1 << endl;
	  return 0;
	}
	int ans = abs(cnt2[0] - cnt2[1]) + abs(cnt3[0] - cnt3[1]) + abs(cnt5[0] - cnt5[1]);
	cout << ans << endl;
}
 
