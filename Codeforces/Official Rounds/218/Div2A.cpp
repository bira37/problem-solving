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
	int n,k;
	cin >> n >> k;
	int v[n];
	for(int i=0; i<n; i++){
	  cin >> v[i];
	}
	int ans =0;
	for(int i=0; i<k; i++){
	  int cnt1 = 0, cnt2 = 0;
	  for(int j=i; j<n; j+=k){
	    if(v[j] == 1) cnt1++;
	    else cnt2++;
	  }
	  ans += min(cnt1, cnt2);
	}
	cout << ans << endl;
	
}
 
