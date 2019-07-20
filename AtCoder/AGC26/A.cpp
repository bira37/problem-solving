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

int32_t main(){
	DESYNC;
	int n;
	int ans = 0;
	cin >> n;
	int v[n];
	for(int i=0; i<n; i++){
	  cin >> v[i];
	}
	int color = -1;
	int qtd = 0;
	for(int i=0; i<n; i++){
	  if(color == -1){
	    color = v[i];
	    qtd = 1;
	    continue;
	  }
	  else if(color != v[i]){
	    ans += qtd/2;
	    qtd = 0;
	    color = -1;
	    i--;
	    continue;
	  }
	  else qtd++;
	}
	ans += qtd/2;
	cout << ans << endl;
}


