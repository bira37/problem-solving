#include <bits/stdc++.h>

#define int long long
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

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	int v[n];
	int c[n];
	int best[n];
	for(int i=0; i<n; i++) cin >> v[i];
	for(int i=0; i<n; i++) cin >> c[i];
	
	for(int i=0; i<n; i++){
	  best[i] = (int)1e15;
	  for(int j=i+1; j<n; j++){
	    if(v[j] > v[i]) best[i] = min(best[i], c[j]);
	  }
	}
	
	int ans = (int)1e15;
	for(int i=0; i<n; i++){
	  for(int j=i+1; j<n; j++){
	    if(v[i] < v[j]) ans = min(ans, c[i] + c[j] + best[j]);
	  }
	}
	
	cout << (ans >= (int)1e15 ? -1 : ans)  << endl; 
}

