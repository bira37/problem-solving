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

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int anc[21][412345];
int dist[21][412345];
int wei[412345];
int cnt = 1;

int32_t main(){
	DESYNC;
	wei[0] = (int)1e16;
	for(int i=0; i<21; i++){
	  for(int j = 0; j<412345; j++){
	    anc[i][j] = 0;
	    dist[i][j] = (int)1e16;
	  }
	}
	
	int q;
	cin >> q;
	int last = 0;
	while(q--){
	  int op;
	  cin >> op;
	  if(op == 1){
	    cnt++;
	    int n, w;
	    cin >> n >> w;
	    
	    n = n ^ last;
	    w = w ^ last;
	    wei[cnt] = w;
	    
	    if(wei[n] >= wei[cnt]) anc[0][cnt] = n;
	    else {
	      int cur = n;
	      for(int i=20; i>=0; i--){
	        if(wei[anc[i][cur]] < wei[cnt]){
	          cur = anc[i][cur];
	        }
	      }
	      anc[0][cnt] = anc[0][cur];
	    }
	    
	    dist[0][cnt] = (anc[0][cnt] == 0 ? (int)1e16 : wei[anc[0][cnt]]);
	    
	    for(int i=1; i<21; i++){
	      anc[i][cnt] = anc[i-1][anc[i-1][cnt]];
	      dist[i][cnt] = (anc[i][cnt] == 0 ? (int)1e16 : dist[i-1][cnt] + dist[i-1][anc[i-1][cnt]]);
	    }
	     
	  }
	  else {
	    int n, w;
	    cin >> n >> w;
	    n = n ^ last;
	    w = w ^ last;
	    
	    if(wei[n] > w){
	      cout << 0 << endl;
	      last = 0;
	      continue;
	    }
	    
	    int ans = 1;
	    int cur = n;
	    w -= wei[n];
	    for(int i=20; i>=0; i--){
	      if(dist[i][cur] <= w){
	        ans += (1LL << i);
	        w -= dist[i][cur];
	        cur = anc[i][cur];
	      }
	    }
	    
	    cout << ans << endl;
	    last = ans;
	  }
	}
	   
}

