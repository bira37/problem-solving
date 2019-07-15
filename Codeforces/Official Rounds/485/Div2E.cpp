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

int n;

int32_t main(){
  DESYNC;
	cin >> n;
	int v[n+1];
	bool vis[n+1];
	int cycle = 0;
	for(int i=1; i<=n; i++){
	  cin >> v[i];
	  vis[i] = false;
	}
	for(int i=1; i<=n; i++){
	  if(!vis[i]){
	    int cur = i;
	    cycle++;
	    while(!vis[cur]){
	      vis[cur] = true;
	      cur = v[cur];
	    }
	  }
	}
	if(cycle%2 == 0) cout << "Petr" << endl;
	else cout << "Um_nik" << endl;
}

