#include <bits/stdc++.h>

#define int unsigned long long
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
	int w,m,k;
	cin >> w >> m >> k;
	int pot = 1;
	int dig = 1;
	int qtd = 9;
	while(pot < m){
	  pot *= 10;
	  dig++;
	}
  dig--;
	int ans = 0;
	while(w > 0){
	  int cnt = pot - m;
	  if(cnt*dig*k <= w){
	    ans += cnt;
	    w -= cnt*dig*k;
	    dig++;
	    m = pot;
	    pot*= 10;
	  }
	  else {
	    int l = 0, r = cnt;
	    int val = -1;
	    while(l <= r){
	      int m = (l+r)>>1;
	      if(m*dig*k <= w){
	        val = m;
	        l = m+1;
	      }
	      else r = m-1;
	    }
	    ans += val;
	    w = 0;
	  }
	}
	cout << ans << endl;
}