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
 
string s;
bool dp[1123][1123];
int mir[26] = {0};
 
int32_t main(){
	DESYNC;
	int t;
	cin >> t;
	mir[0] = 1;
  mir[7] = 1;
  mir[8] = 1;
  mir[12] = 1;
  mir[14] = 1;
  mir[19] = 1;
  mir[20] = 1;
  mir[21] = 1;
  mir[22] = 1;
  mir[23] = 1;
  mir[24] = 1;
	while(t--){
	  cin >> s;
	  int n = s.size();
	  for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	      dp[i][j] = false;
	    }
	  }
	  for(int i=0; i<n; i++){
	    int l = i-1, r = i+1;
	    dp[i][i] = true;
	    while(l >= 0 && r < n && s[l] == s[r]) dp[l--][r++] = true;
	    l = i-1, r = i;
	    while(l >= 0 && r < n && s[l] == s[r]) dp[l--][r++] = true;
	    l = i, r = i+1;
	    while(l >= 0 && r < n && s[l] == s[r]) dp[l--][r++] = true;
	  }
	  int p[n];
	  p[0] = mir[s[0]-'A'];
	  for(int i=1; i<n; i++){
	    p[i] = p[i-1] + mir[s[i]-'A'];
	  }
	  int mx = 0;
	  for(int i=0; i<n; i++){
	    for(int j=i; j<n; j++){
	      //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
	      if(dp[i][j] && p[j] - (i-1 >= 0 ? p[i-1] : 0) == j-i+1) mx = max(mx, j-i+1);
	    }
	  }
	  cout << mx << endl;
	}
	  
}
 
