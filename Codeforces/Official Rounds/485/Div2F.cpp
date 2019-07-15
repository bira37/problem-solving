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

int n,m;

bool vis[(1<<23)-1];
bool has[(1<<23)-1];

void go(int x){
  if(vis[x]) return;
  vis[x] = true;
  for(int b = 0; b < n; b++){
    if((1 << b) & x) go((1<<b) ^ x);
  }
  if(has[x]){
    go((1<<n)-1-x);
  }
}

int32_t main(){
  DESYNC;
	cin >> n >> m;
	for(int i=0; i<m; i++){
	  int x;
	  cin >> x;
	  has[x] = true;
	}
	int ans = 0;
	for(int i=0; i<(1<<n); i++){
	  if(!vis[i] && has[i]){
	    go((1<<n)-1-i);
	    ans++;
	  }
	}
	cout << ans << endl; 
}

