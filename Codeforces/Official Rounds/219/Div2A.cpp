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
	int cnt[10];
	for(int i=0; i<10; i++) cnt[i] = 0;
	int n;
	cin >> n;
	for(int i=0; i<4; i++){
	  string s;
	  cin >> s;
	  for(char c : s){
	    if(c < '0' || c > '9') continue;
	    cnt[c-'0']++;
	  }
	}
	bool ok = true;
	for(int i=0; i<10; i++){
	  if(cnt[i] > 2*n) ok = false;
	}
  cout << (ok ? "YES" : "NO") << endl;
}